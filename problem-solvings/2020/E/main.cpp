#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define MAX_NR_EMP   (120)
#define MAX_NR_TF    (100)

int T, N, M;

struct emp
{
	int o, d;
};

struct tf
{
	int nr;
	int mem[MAX_NR_EMP+1];
	int pen;
};

struct emp emps[MAX_NR_EMP+1];
struct tf tfs[MAX_NR_TF+1];

int main(void)
{
	int t = 0, n, m;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

problem:
	cin >> N >> M;

	for (n = 1; n <= N; n++)
	{
		int o, d;
		cin >> o >> d;
		emps[n] = {o, d};
	}

	for (m = 1; m <= M; m++)
	{
		int nr, pen;

		cin >> nr >> pen;

		tfs[m].nr = nr;
		tfs[m].pen = pen;

		for (n = 1; n <= nr; n++)
			cin >> tfs[m].mem[n];
	}

	int maxval = INT_MIN, maxmask, mask;

	for (mask = 0; mask < (1 << 16); mask++)
	{
		int op = 0, dp = 0, p = 0;

		for (n = 0; n < 16; n++)
		{
			/* emps[n+1] is offense */
			if (mask & (1 << n))
				op += emps[n+1].o;

			/* emps[n+1] is defense */
			else
				op += emps[n+1].d;
		}

		/* calculate pan */
		for (m = 1; m <= M; m++)
		{
			int i, j;
			for (i = 1; i <= tfs[m].nr; i++)
			{
				for (j = i+1; j <= tfs[m].nr; j++)
				{
					bool ti, tj;

					ti = !!(mask & (1 << (tfs[m].mem[i]-1)));
					tj = !!(mask & (1 << (tfs[m].mem[j]-1)));

					if (ti != tj)
						p += tfs[m].pen;
				}
			}
		}

		if (op + dp - p > maxval)
		{
			maxval = op + dp - p;
			maxmask = mask;
		}
	}

	cout << maxval << "\n";

	int nrmem = 0;
	for (n = 0; n < 16; n++)
	{
		if (maxmask & (1 << n))
			nrmem++;
	}
	
	cout << nrmem << " ";

	for (n = 0; n < 16; n++)
	{
		if (maxmask & (1 << n))
			cout << n+1 << " ";
	}

	cout << "\n";

	if (++t < T)
		goto problem;

	return 0;
}
