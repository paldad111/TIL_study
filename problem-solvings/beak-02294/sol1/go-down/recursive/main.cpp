#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ncoin, val;
int coin[100+1];
long long dp[100+1][10000+1];

long long countcoin(int i, int r)
{
	int k;
	long long count = -1;

	/* base condition 1 */
	if (r == 0)
		return 0;
	
	if (r < 0)
		return -1;

	if (dp[i][r])
		return dp[i][r];

	for (k = i; k >= 1; k--)
	{
		int tmp = countcoin(k, r - coin[k]);

		if (tmp != -1)
		{
			if (count == -1 || tmp + 1 <  count)
				count = tmp + 1;
		}
	}

	return dp[i][r] = count;
}

int main(void)
{
	int i;
	long long count = 0;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> ncoin;
	cin >> val;

	/* special condition 1 */
	if (ncoin == 0)
	{
		cout << "0\n";
		return 0;
	}

	for (i = 1; i <= ncoin; i++)
	{
		cin >> coin[i];
	}

	/* special condition 2 */
	if (ncoin == 1)
	{
		if (val % coin[1] == 0)
		{
			cout << "1\n";
			return 0;
		}
		else
		{
			cout << "-1\n";
			return 0;
		}
	}

	cout << countcoin(ncoin, val) << "\n";

	return 0;
}
