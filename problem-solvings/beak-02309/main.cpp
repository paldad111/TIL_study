#include <iostream>
#include <algorithm>

using namespace std;

int sum;
int height[10];

int main(void)
{
	int i, j, k;

	cin.tie(0);
	ios::sync_with_stdio(false);

	for (i = 1; i <= 9; i++)
	{
		cin >> height[i];
		sum += height[i];
	}

	sort(&height[1], &height[10]);

	for (i = 1; i <= 8; i++)
	{
		for (j = i + 1; j <= 9; j++)
		{
			if (sum - height[i] - height[j] == 100)
				goto done;
		}
	}


done:
	for (k = 1; k <= 9; k++)
	{
		if (k == i || k == j)
			continue;

		cout << height[k] << "\n";
	}

	return 0;
}
