#include <iostream>

using namespace std;

int N;
int seq[10000+1];

bool prev_permutation(int *a, int n)
{
	int i, j;

	/* 1 3 5 4 2
	 * 1 4 2 3 5
	 * */
	for (i = n; i >= 2; i--)
	{
		if (a[i-1] > a[i])
			break;
	}

	if (i == 1)
		return false;

	for (j = n; j >= i; j--)
	{
		if (a[i-1] > a[j])
			break;
	}

	swap(a[i-1], a[j]);

	while (i < n)
	{
		swap(a[i], a[n]);
		i++;
		n--;
	}

	return true;
}

int main(void)
{
	int n;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;

	for (n = 1; n <= N; n++)
		cin >> seq[n];

	if (prev_permutation(seq, N))
	{
		for (n = 1; n <= N; n++)
			cout << seq[n] << " ";

		cout << "\n";
	}
	else
	{
		cout << "-1\n";
	}

	return 0;
}
