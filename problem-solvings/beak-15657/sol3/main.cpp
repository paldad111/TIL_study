#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int V[8+1];
int seq[8+1];
int cnt[8+1];

void func(int i, int j, int n)
{
	int k;

	/* base condition 1 - M number selected */
	if (i > M)
	{
		int r;

		for (k = 1; k < n; k++)
		{
			for (r = 1; r <= cnt[k]; r++)
			{
				cout << seq[k] << " ";
			}
		}
		cout << "\n";

		return;
	}

	/* base condition 2 - no number to select */
	if (j > N)
		return;

	/* choose V[j] in seq[i] */
	seq[n] = V[j];
	for (k = M - i + 1; k >= 1; k--)
	{
		cnt[n] = k;
		func(i+k, j+1, n+1);
	}

	func(i, j+1, n);
}

int main(void)
{
	int n;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (n = 1; n <= N; n++)
		cin >> V[n];

	sort(&V[1], &V[N+1]);

	func(1, 1, 1);

	return 0;
}
