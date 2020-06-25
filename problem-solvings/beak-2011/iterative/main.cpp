#include <iostream>
#include <cstring>

using namespace std;

char str[5000+2];
long long count[5000+1];

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

	/* base condition */
	count[0] = 1;
	count[1] = 1;

	for (i = 2; i <= length; i++)
	{
		int v1, v2;
		int c = 0;

		v1 = str[i] - '0';
		v2 = str[i-1] - '0';

		if (v1 != 0)
		{
			c += count[i-1];
			c %= 1000000;
		}

		if (v2 != 0 && v2 * 10 + v1 <= 26)
		{
			c += count[i-2];
			c %= 1000000;
		}

		count[i] = c;
	}

	cout << count[length] << endl;

	return 0;

err:
	cout << 0 << endl;

	return 0;
}
