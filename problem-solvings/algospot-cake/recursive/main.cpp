#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ncake;
int spending[40+1];
int dp[40+1][40+1][40+1];

int max3(int a, int b, int c)
{
	return max(a, max(b, c));
}

int min3(int a, int b, int c)
{
	return min(a, min(b, c));
}

int threebake(int i, int j, int k, int c1, int c2, int c3)
{
	int next, n1, n2, n3;

	if (i > ncake || j > ncake || k > ncake)
		return max3(c1, c2, c3);

	//if (dp[i][j][k] != -1)
	//	return dp[i][j][k];

	next = max3(i, j, k) + 1;

	n1 = threebake(next, j, k, c1 + spending[next], c2, c3);
	n2 = threebake(i, next, k, c1, c2 + spending[next], c3);
	n3 = threebake(i, j, next, c1, c2, c3 + spending[next]);

	return dp[i][j][k] = min3(n1, n2, n3);
}

int main(void)
{
	int n;

	cin.tie(0);
	ios::sync_with_stdio(false);

	while (true)
	{
		cin >> ncake;

		if (ncake == 0)
			break;

		for (n = 1; n <= ncake; n++)
			cin >> spending[n];

		memset(dp, 0xff, sizeof(dp));

		cout << threebake(0, 0, 0, 0, 0, 0) << "\n";
	}

	return 0;
}
