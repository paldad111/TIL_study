#include <iostream>

using namespace std;

int N, M;
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

	for (k = j; k <= N; k++)
	{
		if (check[k])
			continue;

		check[k] = true;
		seq[i] = k;

		func(i+1, k+1);

		check[k] = false;
	}
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	func(1, 1);

	return 0;
}
