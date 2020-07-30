#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T, N;
char str[500+2];
long long cache[500+1][500+1];

bool matchable(int i, int j)
{
	return (str[i] == '*' && str[j] == '*') ||
		(str[i] == '*' && str[j] == ')') ||
		(str[i] == '*' && str[j] == ']') ||
		(str[i] == '*' && str[j] == '}') ||
		(str[i] == '(' && str[j] == '*') ||
		(str[i] == '[' && str[j] == '*') ||
		(str[i] == '{' && str[j] == '*') ||
		(str[i] == '(' && str[j] == ')') ||
		(str[i] == '[' && str[j] == ']') ||
		(str[i] == '{' && str[j] == '}');
}

bool openable(int i)
{
	return str[i] == '*' || str[i] == '(' || str[i] == '{' || str[i] == '[';
}

long long dp(int i, int j)
{
	int k;
	long long rtn;

	//cout << i << ", " << j << endl;

	/* base condition */
	if (i > j)
		return 0;

	/*
	if (i == j)
		return 1;
	*/

	if (cache[i][j] != -1)
		return cache[i][j];

	rtn = dp(i+1, j) + 1;

	/* if no match - erase all */
	//rtn = j - i + 1;

	/* 분할하는 경우 */
	for (k = i+1; k <= j; k++)
	{
		if (matchable(i, k))
		{
			int M;
			long long tmp;

			tmp = dp(i+1, k-1) + dp(k+1, j);
			rtn = min(tmp, rtn);
		}
	}

	return cache[i][j] = rtn;
}

int main(void)
{
	int t = 0, n, result;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;
problem:

	cin >> &str[1];

	memset(cache, 0xff, sizeof(cache));

	result = dp(1, strlen(&str[1]));

	cout << result << "\n";

	if (++t < T)
		goto problem;

	return 0;
}
