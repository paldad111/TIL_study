#include <iostream>

using namespace std;

int cache[1000000 + 1];

int count(int n)
{
	int ret;
	int c1, c2, c3;

	/* base condition */
	if (n <= 1)
		return 0;

	ret = cache[n];
	if (ret > 0)
		return ret;

	c1 = c2 = c3 = 0x7fffffff;

	/* case 1 */
	if (n - 1 >= 0)
		c1 = count(n-1) + 1;

	/* case 2 */
	if (!(n%2))
		c2 = count(n/2) + 1;

	/* case3 */
	if (!(n%3))
		c3 = count(n/3) + 1;

	ret = min(min(c1, c2), c3);
	cache[n] = ret;

	return ret;
}

int main(void)
{
	int n;

	cin >> n;

	for (int i = 0; i <= n; i++)
		cache[i] = -1;

	cout << count(n) << endl;

	return 0;
}
