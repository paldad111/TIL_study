#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char input_str[2500+1];

/* optimization 1 = double memoization table */

/* cache[i] = minimum split of substring[0..i-1] */
int cache[2500+1];
int ispal[2500][2500+1];

bool is_palindrome(int s, int l)
{
    int ret = true;

    ret = ispal[s][l];
    if (ret != -1)
        goto out;

    /* base condition 1 */
    if (l == 1)
    {
        ret = true;
        goto out_cache;
    }

    /* base condition 2 */
    if (l == 2)
    {
        if (input_str[s] == input_str[s+1])
            ret = true;
        else
            ret = false;
        goto out_cache;
    }

    if (input_str[s] != input_str[s+l-1] ||
        !is_palindrome(s+1, l-2))
        ret = false;

out_cache:
    ispal[s][l] = ret;
out:
    return ret;
}

int count_mininum_split(int l)
{
	int minimum = 0x7fffffff;

	/* base condition 2: */
	if (l == 1)
		return 1;

	if (cache[l] != -1)
		return cache[l];

	/* optimization 2 = calculate best */

	/* best - string is pal */
	if (is_palindrome(0, l))
	{
		cache[l] = 1;
		return 1;
	}

	bool *leftpal  = new bool [l];
	bool *rightpal = new bool [l];

#if 0
	l = 5

	0 1 2 3 4
	a b c d e

	i = 2 [0 2][2 3]
	i = 3 [0 3][3 2]
	i = 4 [0 4][4 1]
#endif
	/* good - left and right palindrom */
	for (int i = 1; i < l; i++)
	{
		if (is_palindrome(0, i))
			leftpal[i] = true;
		else
			leftpal[i] = false;
			
		if (is_palindrome(i, l-i))
			rightpal[i] = true;
		else
			rightpal[i] = false;

		if (leftpal[i] && rightpal[i])
		{
			minimum = 2;
			goto out;
		}
	}

#if 0
	l = 5

	0 1 2 3 4
	a b c d e

	i = 2 [0 2][2 3]
	i = 3 [0 3][3 2]
#endif
	/* notbad, one of left or right pal */
	for (int i = 1; i < l; i++)
	{
		int left;

		if (!rightpal[i])
			continue;

		left = count_mininum_split(i);

		minimum = min(minimum, 1 + left);

		/* optimization 3 = fast break in notbad case */
		if (minimum == 3)
			goto out;
	}


out:
	delete [] leftpal;
	delete [] rightpal;
	cache[l] = minimum;

	return minimum;
}

int main()
{
	cin >> input_str;

	memset(cache, 0xff, sizeof(cache));
	memset(ispal, 0xff, sizeof(ispal));

	cout << count_mininum_split(strlen(input_str)) << endl;

	return 0;
}
