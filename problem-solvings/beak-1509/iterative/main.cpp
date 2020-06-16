#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char input_str[2500+1];

/* cache[i] = minimum split of substring[0..i] */
int cache[2500];
bool ispal[2500][2500+1];

int count_mininum_split(int s, int l)
{
	/* length 1 is pal */
	for (int j = 0; j < l; j++)
		ispal[j][1] = true;

	/* length 2 is pal iff */
	for (int j = 0; j < l-1; j++)
	{
		if (input_str[j] == input_str[j+1])
			ispal[j][2] = true;
		else
			ispal[j][2] = false;
	}

	/* i is length */
	for (int i = 3; i <= l; i++)
	{
#if 0
		l = 5
		0 1 2 3 4
		a b c d e

		i == 3
		j = 0 1 2
		i == 4
		j = 0 1
		i == 5
		j = 0
#endif
		/* j is start idx */
		for (int j = 0; j <= l - i; j++)
		{
			if (input_str[j] == input_str[j+i-1] && ispal[j+1][i-2])
				ispal[j][i] = true;
			else
				ispal[j][i] = false;
		}
	}

	/* special condition */

	/* minsplit of str[0..0] is 1 */
	cache[1] = 1;

	/* i is length */
	for (int i = 2; i <= l; i++)
	{
		int minsplit = 0x7fffffff;

		/* substring[0..i] is pal */
		if (ispal[0][i])
		{
			minsplit = 1;
			goto next;
		}

#if 0
		i == 3
		s 0 1 2
		  a b c

		j = 1
		str(0, 1),str(1, 2)
		  = 2
		str(0, 2),str(2, 1)

		i == 5
		s 0 1 2 3 4
		  a b c d e

		j = 1
		str(0, 1),str(1, 4)
		  = 2
		str(0, 2),str(2, 3)
		  = 3
		str(0, 3),str(3, 2)
		  = 4
		str(0, 4),str(4, 1)
#endif

		/**
		 * split substring[0..i] to
		 * substring[0..j] and substring[j+1..i]
		 */
		for (int j = 1; j < i; j++)
		{
			if (ispal[j][i-j] && (cache[j] + 1 < minsplit))
				minsplit = cache[j] + 1;
		}
next:
		cache[i] = minsplit;
	}

	return cache[l];
}

int main()
{
	cin >> input_str;

	memset(cache, 0xff, sizeof(cache));
	memset(ispal, 0x00, sizeof(ispal));

	cout << count_mininum_split(0, strlen(input_str)) << endl;

	return 0;
}
