#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int length;
int gridval[100+1][100+1];
unsigned long long dp[100+1][100+1];

int main(void)
{
	int i, j;

	cin >> length;

	/* special condition */
	if (length == 0)
	{
		cout << 0 << endl;
		return 0;
	}

	for (i = 1; i <= length; i++)
	{
		for (j = 1; j <= length; j++)
		{
			cin >> gridval[i][j];
		}
	}

	/* base condition */
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;

	for (i = 1; i <= length; i++)
	{
		for (j = 1; j <= length; j++)
		{
			int jump = gridval[i][j];

			/* trap */
			if (jump == 0)
				continue;

			/* down */
			if (i + jump <= length)
				dp[i + jump][j] += dp[i][j];

			/* right */
			if (j + jump <= length)
				dp[i][j + jump] += dp[i][j];
		}
	}

	cout << dp[length][length] << endl;

	return 0;
}
