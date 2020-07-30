#include <iostream>

using namespace std;

int N, M;
int seq[8+1];
int cnt[8+1];

void func(int i, int j, int n)
{
	int k;

	/* base condition 1 - choose M number */
	if (i > M)
	{
		for (k = 1; k < n; k++)
		{
			int r;

			for (r = 1; r <= cnt[k]; r++)
				cout << seq[k] << " ";
		}
		cout << "\n";

		return;
	}

	/* base condition 2 - no number to choose */
	if (j > N)
		return;

	/* choose j to seq[i] - M-i, M-i-1, M-i-2, .. 1 */
	seq[n] = j;
	for (k = M-i+1; k >= 1; k--)
	{
		cnt[n] = k;
		func(i+k, j+1, n+1);
	}

	/* do not choose j to seq[i] */
	func(i, j+1, n);
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	func(1, 1, 1);

	return 0;
}
