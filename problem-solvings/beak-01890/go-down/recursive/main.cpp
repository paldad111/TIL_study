#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int length;
bool check[100+1][100+1];
int gridval[100+1][100+1];
unsigned long long cache[100+1][100+1];

int count_go_down(int i, int j)
{
	int k;
	unsigned long long count = 0;

	/* base condition */
	if (i == 1 && j == 1)
		return 1;

	if (i < 1 || j < 1)
		return 0;

	if (check[i][j])
		return cache[i][j];

	for (k = i - 1; k >= 1; k--)
	{
		if (gridval[k][j] == i - k)
			count += count_go_down(k, j);
	}

	for (k = j - 1; k >= 1; k--)
	{
		if (gridval[i][k] == j - k)
			count += count_go_down(i, k);
	}

	check[i][j] = true;

	return cache[i][j] = count;
}

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

	memset(check, 0, sizeof(check));

	cout << count_go_down(length, length) << endl;

	return 0;
}

