#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int V[8+1];

int seq[8+1];
bool check[8+1];

void func(int i, int j)
{
	int k;

	/* base condition */
	if (i > M)
	{
		for (k = 1; k <= M; k++)
			cout << seq[k] << " ";

		cout << "\n";

		return;
	}

	for (k = j+1; k <= N; k++)
	{
		if (check[k])
			continue;

		check[k] = true;

		seq[i] = V[k];
		func(i+1, k);

		check[k] = false;

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

	func(1, 0);

	return 0;
}
