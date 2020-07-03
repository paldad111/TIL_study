#include <iostream>

using namespace std;

int T;
int V[100+1];

int gcd(int a, int b)
{
	int v1, v2;

	v1 = max(a, b);
	v2 = min(a, b);

	if (v2 == 0)
		return 0;

	if (v1 % v2 == 0)
		return v2;

	return gcd(v2, v1 % v2);
}

int main(void)
{
	int i, j, N, t;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

	for (t = 1; t <= T; t++)
	{
		long long gcdsum = 0;

		cin >> N;

		for (i = 1; i <= N; i++)
			cin >> V[i];

		for (i = 1; i <= N; i++)
		{
			for (j = i+1; j <= N; j++)
			{
				gcdsum += gcd(V[i], V[j]);
			}
		}

		cout << gcdsum << "\n";
	}

	return 0;
}
