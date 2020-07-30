#include <iostream>

using namespace std;

int N, M;
int seq[8+1];

void func(int i, int j)
{
	int k;

	if (i > M)
	{
		for (k = 1; k <= M; k++)
			cout << seq[k] << " ";
		cout << "\n";

		return;
	}

	for (k = j; k <= N; k++)
	{
		seq[i] = k;
		func(i+1, k);
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
