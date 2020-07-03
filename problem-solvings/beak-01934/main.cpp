#include <iostream>

using namespace std;

int A, B, T;

int gcd(int a, int b)
{
	int v1, v2;

	v1 = max(a, b);
	v2 = min(a, b);

	if (v1 % v2 == 0)
		return v2;

	return gcd(v2, v1 % v2);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main(void)
{
	int t;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;
	
	for (t = 1; t <= T; t++)
	{
		cin >> A >> B;

		cout << lcm(A, B) << "\n";
	}

	return 0;
}
