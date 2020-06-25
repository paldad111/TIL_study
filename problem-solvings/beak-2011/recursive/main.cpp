#include <iostream>
#include <cstring>

using namespace std;

char str[5000+2];
long long cache[5000+1];

int count(int len)
{
	int v1, v2;
	long long t = 0;

	/* base condition 1 */
	if (len < 0)
		return 0;

	/* base condition 2 */
	if (len == 0)
		return 1;

	/* base condition 3 */
	if (len == 1)
		return 1;

	if (cache[len] != -1)
		return cache[len];

	v1 = str[len] - '0';
	v2 = str[len-1] - '0';

	if (v1 != 0) {
		t += count(len - 1);
		t %= 1000000;
	}

	if (v2 != 0 && v2 * 10 + v1 <= 26)
	{
		t += count(len - 2);
		t %= 1000000;
	}

	return cache[len] = t;
}

int main(void)
{
	int i, length;

	cin >> &str[1];

	length = strlen(str+1);

	/* check special case */
	if (length == 0)
		goto err;

	/* check error condition 1 */
	if (str[1] == '0')
		goto err;

	/* check error condition 2 */
	for (i = 1; i <= length; i++)
	{
		if (i > 1 && str[i] == '0' && str[i-1] == '0')
			goto err;
	}

	memset(cache, 0xff, sizeof(cache));

	cout << count(length) << endl;

	return 0;

err:
	cout << 0 << endl;

	return 0;
}
