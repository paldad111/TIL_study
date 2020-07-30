#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int T, N, M, X;
int MAT[300+1][150+1];

#if 0
/* for non-negative value */
int count_le_x(int *arr)
{
	int s, e, cnt, sum;

	s = e = 1;
	cnt = 0;
	sum = arr[1];

	while (s <= M && e <= M)
	{
//		cout << s << ", " << e << endl;

		if (sum <= X)
		{
			e++;

			if (e >= s)
			{
//				cout << "add cnt, " << e << " - " << s << endl;
				cnt += e - s;
				if (e <= M && arr[e] > X)
					cnt--;
			}

			if (e <= M)
				sum += arr[e];
		}
		else
		{
//			cout << "move s++" << endl;
			sum -= arr[s];
			s++;
		}
	}
	
	return cnt;
}
#else
int count_le_x(int *arr)
{
}
#endif

int main(void)
{
#if 0
	X = 3;
	M = 3;
	int C[] = {0/**/, 1, -5, 5};
	cout << count_le_x(C) << endl;

	cout << "----------------\n";

	X = 3;
	M = 1;
	int A[] = {0/**/, 1};
	cout << count_le_x(A) << endl;

	cout << "----------------\n";

	X = 5;
	M = 2;
	int B[] = {0/**/, 1, 2};
	cout << count_le_x(B) << endl;

	cout << "----------------\n";

	return 0;
#endif

	int t = 0, n, m;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

problem:
	cin >> N >> M >> X;

	for (n = 1; n <= N; n++)
	{
		for (m = 1; m <= M; m++)
		{
			cin >> MAT[n][m];
		}
	}

	int i, j, k;
	int cnt = 0;
	int SUM[150+1];

	for (i = 1; i <= N; i++)
	{
		memset(SUM, 0, sizeof(SUM));

		for (j = i; j <= N; j++)
		{
			for (k = 1; k <= M; k++)
				SUM[k] += MAT[j][k];

			cnt += count_le_x(SUM);
		}
	}

	cout << cnt << "\n";

	if (++t < T)
		goto problem;

	return 0;
}
