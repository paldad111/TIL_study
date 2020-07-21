#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int V[8+1];
int seq[8+1];

void func(int i)
{
	int j;

	/* base condition */
	if (i > M)
	{
		for (j = 1; j <= M; j++)
			cout << seq[j] << " ";
		cout << "\n";

		return;
	}

	for (j = 1; j <= N; j++)
	{
		seq[i] = V[j];
		func(i+1);
	}
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

	func(1);

	return 0;
}
