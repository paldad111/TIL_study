#include <iostream>

using namespace std;

int N, M;
int seq[7+1];

void func(int i)
{
	int j;

	if (i > M)
	{
		for (j = 1; j <= M; j++)
			cout << seq[j] << " ";
		cout << "\n";

		return;
	}

	for (j = 1; j <= N; j++)
	{
		seq[i] = j;
		func(i+1);
	}
}

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	func(1);

	return 0;
}
