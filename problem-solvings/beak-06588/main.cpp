#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ninput, maxnum = INT_MIN;
int testnum[100000+1];
bool notprime[1000000+1];

inline bool isprime(int num)
{
	return !notprime[num];
}

void primecheck(int maxnum)
{
	int p, n;

	notprime[1] = true;
	notprime[2] = false;

	for (p = 2; p * p <= maxnum; p++)
	{
		if (isprime(p))
		{
			for (n = p*p; n <= maxnum; n+=p)
				notprime[n] = true;
		}
	}
}

int main(void)
{
	int i, ntest;

	cin.tie(0);
	ios::sync_with_stdio(false);

	for (ninput = 1; ; ninput++)
	{
		cin >> testnum[ninput];

		if (testnum[ninput] == 0)
			break;

		maxnum = max(maxnum, testnum[ninput]);
	}

	primecheck(maxnum);

	for (ntest = 1; ntest < ninput; ntest++)
	{
		int val = testnum[ntest];

		for (i = 1; i <= val; i++)
		{
			if (isprime(i) && isprime(val - i))
			{
				cout << val << " = " << i << " + " << val - i << "\n";
				break;
			}
		}
	}

	return 0;
}

