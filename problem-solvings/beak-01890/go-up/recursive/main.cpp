#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int length;
bool check[100+1][100+1];
int gridval[100+1][100+1];
unsigned long long cache[100+1][100+1];

unsigned long long count_go_up(int i, int j)
{
	int c1, c2;

	/* base condition 1 */
	if (i == length && j == length)
		return 1;

	/* base condition 2 */
	if (i > length || j > length)
		return 0;

	/* base condition 3 */
	if (gridval[i][j] == 0)
		return 0;

	if (check[i][j])
		return cache[i][j];

	c1 = count_go_up(i + gridval[i][j], j);
	c2 = count_go_up(i, j + gridval[i][j]);

	check[i][j] = true;
	return cache[i][j] = c1 + c2;
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

	cout << count_go_up(1, 1) << endl;

	return 0;
}
