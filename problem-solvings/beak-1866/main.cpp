#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int nr_items;
int item_cost[3000+2];
int mincost[3000+1][3000+1];
int cache[3000+1][3000+2];
int tcost, hcost;

bool cmp(const int &a, const int &b)
{
	return a < b;
}

int calc(int p, int n)
{
	int cost = 0;
	int cost1, cost2;

	if (n == INT_MAX)
		n = 3001;

	if (cache[p][n] != -1)
		return cache[p][n];

	for (int i = 1; i <= nr_items; i++)
	{
		if (i <= p)
			continue;

		if (i > n)
			continue;

		cost1 = (item_cost[i] - item_cost[p]) * tcost;
		cost2 = (item_cost[n] - item_cost[i]) * tcost;

		cost += min(cost1, cost2);
	}

	return cache[p][n] = cost;
}

int main(void)
{
	int cost = 0;
	int total_minimal = INT_MAX;

	cin >> nr_items;

	if (nr_items == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	for (int i = 1; i <= nr_items; i++)
	{
		cin >> item_cost[i];
	}

	cin >> tcost;
	cin >> hcost;

	memset(cache, 0xff, sizeof(cache));

	sort(&item_cost[1], &item_cost[nr_items+1], cmp);

	/* base condition */
	item_cost[0] = 0;
	item_cost[3001] = 1000000;
	cost = calc(0, INT_MAX);
	cout << cost << endl;
	return 0;
	for (int i = 0; i <= nr_items; i++)
	{
		mincost[0][i] = cost;
		mincost[i][0] = cost;
	}

	total_minimal = cost;

	for (int nstop = 1; nstop <= nr_items; nstop++)
	{
		for (int i = 1; i <= nr_items; i++)
		{
			int cost = INT_MAX;

			for (int j = 0; j < i; j++)
			{
				cost = min(cost, mincost[nstop-1][j] -
						 calc(j, INT_MAX) +
						 calc(j, i) +
						 calc(i, INT_MAX) +
						 hcost);

			}

			mincost[nstop][i] = cost;

			total_minimal = min(total_minimal, cost);
		}
	}

	cout << total_minimal << endl;

	return 0;
}
