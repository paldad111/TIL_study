#include <iostream>
#include <algorithm>

using namespace std;

int N;
int seq[9];

int main(void)
{
	int n;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	for (n = 1; n <= N; n++)
		seq[n] = n;

	do
	{
		for (n = 1; n <= N; n++)
			cout << seq[n] << " ";
		cout << "\n";
	}
	while (next_permutation(&seq[1], &seq[N+1]));

	return 0;
}
