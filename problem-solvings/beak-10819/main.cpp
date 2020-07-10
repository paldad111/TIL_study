#include <iostream>
#include <algorithm>

using namespace std;

int N;
int seq[8+1];

int main(void)
{
	int n, sum, maxima;

	cin >> N;

	for (n = 1; n <= N; n++)
		cin >> seq[n];

	sort(&seq[1], &seq[N+1]);

	maxima = 0;

	do
	{
		sum = 0;

		for (n = 1; n <= N-1; n++)
			sum += abs(seq[n] - seq[n+1]);

		maxima = max(maxima, sum);

	}
	while (next_permutation(&seq[1], &seq[N+1]));

	cout << maxima << "\n";

	return 0;
}
