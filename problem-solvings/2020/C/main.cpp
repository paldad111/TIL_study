#include <iostream>
#include <algorithm>

using namespace std;

int T, N, M, X;
int MAT[300+1][150+1];
int SUM[300+1][150+1];

int main(void)
{
	int t = 0, n;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

problem:
	cin >> N >> X;

	for (n = 1; n <= N; n++)
		V[n] = n;

	bool found = false;

	do
	{
		bool alice = true;
		int i = 1, j = N;
		int v1 = 0, v2 = 0;

		while (i <= j)
		{
			if (V[i] > V[j])
			{
				if (alice)
					v1 += V[i];
				else
					v2 += V[i];
				i++;
			}
			else
			{
				if (alice)
					v1 += V[j];
				else
					v2 += V[j];
				j--;
			}

			alice = !alice;
		}

		if (v1 - v2 == X)
		{
			found = true;
			break;
		}
	}
	while (next_permutation(&V[1], &V[N+1]));

	if (found)
	{
		cout << "YES\n";
		for (n = 1; n <= N; n++)
			cout << V[n] << " ";
		cout << "\n";
	}
	else
	{
		cout << "NO\n";
	}


	if (++t < T)
		goto problem;

	return 0;
}
