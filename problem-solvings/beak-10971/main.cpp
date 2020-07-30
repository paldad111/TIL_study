#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int N;
int M[10+1][10+1];
int seq[10+1];

int main(void)
{
	int i, j, n, sum, minima;

	cin >> N;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			cin >> M[i][j];
		}
	}

	for (i = 1; i <= N; i++)
		seq[i] = i;

	minima = INT_MAX;

	do
	{
		sum = 0;

		for (n = 1; n <= N; n++)
		{
			int cost;

			if (n == N)
				cost = M[seq[n]][seq[1]];
			else
				cost = M[seq[n]][seq[n+1]];

			if (cost == 0)
			{
				sum = INT_MAX;
				break;
			}

			sum += cost;
		}

		minima = min(minima, sum);

	}
	while (next_permutation(&seq[1], &seq[N+1]));

	cout << minima << "\n";

	return 0;
}
