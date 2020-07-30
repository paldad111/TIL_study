#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, W;
int spot[1000+1][2];
int trace[1000+1][1000+1][2];
int cache[1000+1][1000+1];
bool check[1000+1][1000+1];

int move1(int f, int t)
{
	int cost;

	if (f == 0)
	{
		cost = (spot[t][0] - 1) +
		       (spot[t][1] - 1);
	}
	else
	{
		cost = abs(spot[t][0] - spot[f][0]) +
		       abs(spot[t][1] - spot[f][1]);
	}

	return cost;
}

int move2(int f, int t)
{
	int cost;

	if (f == 0)
	{
		cost = (N - spot[t][0]) +
		       (N - spot[t][1]);
	}
	else
	{
		cost = abs(spot[t][0] - spot[f][0]) +
		       abs(spot[t][1] - spot[f][1]);
	}

	return cost;
}

int dp(int i, int j)
{
	int next;
	int c1, c2;

	if (i >= W || j >= W)
		return 0;

	if (check[i][j])
		return cache[i][j];

	next = max(i, j) + 1;

	c1 = dp(next, j) + move1(i, next);
	c2 = dp(i, next) + move2(j, next);

#if 0
	cout << i << ", " << j << endl;
	cout << " c1: " << c1 << endl;
	cout << " c2: " << c2 << endl;
#endif

	if (c1 < c2)
	{
		trace[i][j][0] = next;
		trace[i][j][1] = j;
	}
	else
	{
		trace[i][j][0] = i;
		trace[i][j][1] = next;
	}

	check[i][j] = true;
	return cache[i][j] = min(c1, c2);
}

int main(void)
{
	int w;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> W;

	for (w = 1; w <= W; w++)
		cin >> spot[w][0] >> spot[w][1];

	cout << dp(0, 0) << "\n";

	int i = 0, j = 0;
	for (w = 1; w <= W; w++)
	{
		int ni, nj;
		//cout << trace[i][j][0] << ", " << trace[i][j][1] << "\n";

		ni = trace[i][j][0];
		nj = trace[i][j][1];

		i = ni;
		j = nj;

		if (i == w)
			cout << "1\n";
		else
			cout << "2\n";
	}

	return 0;
}
