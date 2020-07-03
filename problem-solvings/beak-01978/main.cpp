#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nr;
int V[100+1];
bool not_prime[1000+1];

inline bool isprime(int i)
{
	return !not_prime[i];
}

void primecheck(int v)
{
	int i, j;

	not_prime[1] = true;
	not_prime[2] = false;

	for (i = 2; i * i <= v; i++)
	{
		if (isprime(i))
		{
			for (j = i * i; j <= v; j += i)
				not_prime[j] = true;
		}
	}
}

int main(void)
{
	int i, n, maxval = INT_MIN;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> nr;

	for (i = 1; i <= nr; i++)
	{
		cin >> V[i];
		maxval = max(maxval, V[i]);
	}

	primecheck(maxval);

	for (i = 1; i <= maxval; i++)
	{
		if (isprime(i))
			cout << i << endl;
	}

	return 0;
}
