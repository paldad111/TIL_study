#include <iostream>
#include <algorithm>

using namespace std;

int N;
int seq[10000+1];

int main(void)
{
	int n;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	for (n = 1; n <= N; n++)
		cin >> seq[n];

	if (next_permutation(&seq[1], &seq[N+1]))
	{
		for (n = 1; n <= N; n++)
			cout << seq[n] << " ";
		cout << "\n";
	}
	else
	{
		cout << "-1\n";
	}

	return 0;
}
