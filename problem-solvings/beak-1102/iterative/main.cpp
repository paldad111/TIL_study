#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int nr_plants, nr_on, nr_to_on;
int matrix_cost[16][16];
char yns[16+1];
int min_cost[1 << 16];
int min_cost_on[1 << 16][16];
vector<int> v[16+1];

int main(void)
{
	int initial_mask = 0;
	int total_cost = 0x7fffffff;

	memset(min_cost, 0xff, sizeof(min_cost));
	memset(min_cost_on, 0xff, sizeof(min_cost_on));

	cin >> nr_plants;

	for (int i = 0; i < nr_plants; i++)
	{
		for (int j = 0; j < nr_plants; j++)
		{
			cin >> matrix_cost[i][j];
		}
	}

	cin >> yns;

	nr_on = 0;
	for (int i = 0; i < nr_plants; i++)
	{
		/* base condition */
		if (yns[i] == 'Y')
		{
			int mask = 1 << i;

			min_cost[mask] = 0;
			nr_on++;

			if (nr_on == 1)
			{
				for (int j = 0; j < nr_plants; j++)
					min_cost_on[mask][j] = matrix_cost[i][j];
			}
			else
			{
				for (int j = 0; j < nr_plants; j++)
					min_cost_on[mask | initial_mask][j] =
						min(min_cost_on[initial_mask][j], matrix_cost[i][j]);
			}

			initial_mask |= mask;
		}
	}

	v[nr_on].push_back(initial_mask);

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

	/* i is number of plants (bits on mask) */
	for (int i = nr_on+1; i <= nr_to_on; i++)
	{
		for (int pmask: v[i-1])
		{
			for (int j = 0; j < nr_plants; j++)
			{
				int nmask = pmask | (1 << j);

				/* dont overlap */
				if (pmask == nmask)
					continue;

				/* first appearance of nmask (turn-on the plant j from pmask) */
				if (min_cost[nmask] == -1)
				{
					v[i].push_back(nmask);
					for (int k = 0; k < nr_plants; k++)
						min_cost_on[nmask][k] = min(min_cost_on[pmask][k],
									    matrix_cost[j][k]);
				}

				/* find new minimal cost to turn-on the plant j */
				if (min_cost[nmask] == -1 ||
				    min_cost[nmask] > min_cost[pmask] + min_cost_on[pmask][j])
				{
					min_cost[nmask] = min_cost[pmask] + min_cost_on[pmask][j];
				}

				if (i == nr_to_on)
					total_cost = min(total_cost, min_cost[nmask]);

			}
		}
	}

	cout << total_cost << endl;

	return 0;
}

