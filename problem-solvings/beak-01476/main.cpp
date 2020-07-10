#include <iostream>

using namespace std;

int E, S, M;

int main()
{
	int n, e, s, m;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> E >> S >> M;

	e = s = m = 0;
	for (n = 1; ; n++)
	{
		e++;
		s++;
		m++;

		if (e > 15)
			e = 1;
		if (s > 28)
			s = 1;
		if (m > 19)
			m = 1;

		if (e == E && s == S && m == M)
			break;
	}

	cout << n << "\n";

	return 0;
}

