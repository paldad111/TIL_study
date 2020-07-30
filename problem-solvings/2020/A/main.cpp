#include <iostream>
#include <algorithm>

using namespace std;

#define NR_MAX_ITEM (100000)

struct profit
{
	int v1;
	int v2;
};

int T, N;
struct profit V[NR_MAX_ITEM];

bool cmp(struct profit a, struct profit b)
{
	return a.v1 + a.v2 > b.v1 + b.v2;
}

int main(void)
{
	int t = 0, n;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

next_test:

	cin >> N;
	for (n = 0; n < N; n++)
		cin >> V[n].v1 >> V[n].v2;
	sort(&V[0], &V[N], cmp);

	int v1 = 0, v2 = 0;

	for (n = 0; n < N; n++)
	{
		if ((n % 2) == 0)
			v1 += V[n].v1;
		else
			v2 += V[n].v2;
	}

	cout << v1 - v2 << "\n";

	if (++t < T)
		goto next_test;

	return 0;
}


