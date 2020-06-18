#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nr_plants, nr_on, nr_to_on;
int on_cost[16][16];
int cache[1 << 16];
int cache_on_cost[1 << 16][16];

int min_poweron_cost(int state, int n)
{
	int j, k;
	int mincost = INT_MAX;

	if (cache[state] != -1)
		return cache[state];

	/* base condition */
	if (n == nr_to_on)
		return 0;

	for (j = 0; j < nr_plants; j++)
	{
		int nstate = state | (1 << j);

		if (nstate == state)
			continue;

		if (cache[nstate] == -1)
		{
			for (k = 0; k < nr_plants; k++)
				cache_on_cost[nstate][k] = min(cache_on_cost[state][k], on_cost[j][k]);
		}

		mincost = min(mincost, min_poweron_cost(nstate, n + 1) + cache_on_cost[state][j]);
	}

	return cache[state] = mincost;
}

int main(void)
{
	int i, j;
	int initial_plant_state = 0;
	char yns[16+1];

	cin >> nr_plants;

	for (i = 0; i < nr_plants; i++)
	{
		for (int j = 0; j < nr_plants; j++)
		{
			cin >> on_cost[i][j];
		}
	}

	cin >> yns;

	nr_on = 0;
	for (i = 0; i < nr_plants; i++)
	{
		if (yns[i] == 'Y')
		{
			int state = 1 << i;

			nr_on++;

			if (nr_on == 1)
			{
				for (j = 0; j < nr_plants; j++)
					cache_on_cost[state][j] = on_cost[i][j];
			}
			else
			{
				for (j = 0; j < nr_plants; j++)
					cache_on_cost[state | initial_plant_state][j] =
						min(cache_on_cost[initial_plant_state][j], on_cost[i][j]);
			}

			initial_plant_state |= state;
		}
	}

	cin >> nr_to_on;

	/* special case */
	if (nr_on >= nr_to_on)
	{
		cout << 0 << endl;
		return 0;
	}

	if (!nr_on)
	{
		cout << -1 << endl;
		return 0;
	}

	memset(cache, 0xff, sizeof(cache));

	cout << min_poweron_cost(initial_plant_state, nr_on) << endl;

	return 0;
}

