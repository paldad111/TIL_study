#include <iostream>

using namespace std;

int count[1000000 + 1];

int main(void)
{
	int n;

	cin >> n;

	/* base condition */
	count[0] = 0;
	count[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		int c1, c2, c3;

		c1 = c2 = c3 = 0x7fffffff;

		if (i - 1 >= 0)
			c1 = count[i-1] + 1;
		if (!(i % 2))
			c2 = count[i/2] + 1;
		if (!(i % 3))
			c3 = count[i/3] + 1;

		count[i] = min(min(c1, c2), c3);
	}

	cout << count[n] << endl;

	return 0;
}
