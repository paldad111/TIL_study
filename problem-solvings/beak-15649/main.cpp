#include <iostream>

using namespace std;

int N, M;
int seq[8+1];
bool check[8+1];

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
		if (check[j])
			continue;

		seq[i] = j;
		check[j] = true;

		func(i+1);

		check[j] = false;

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
