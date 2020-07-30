#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define NR_MAX_NODE (300000)
#define NR_MAX_EDGE (400000)

#define EMPTY       0
#define RED         1
#define BLUE        2

int T, N, M;

struct hate
{
	int f;
	int t;
};

struct hate hates[NR_MAX_EDGE * 2 + 1];
int nr_hates;
int hates_cnt[NR_MAX_NODE+1];

bool cmp(struct hate a, struct hate b)
{
	if (a.f != b.f)
		return a.f < b.f;
	else
		return a.t < b.t;
}

int color[NR_MAX_EDGE+1];

bool coloring(int u, int c)
{
	int idx, v, next_color;

	color[u] = c;

	next_color = c == RED ? BLUE : RED;

	for (idx = hates_cnt[u-1]; idx < hates_cnt[u]; idx++)
	{
		v = hates[idx].t;

		if (color[v] == c)
			return false;

		if (color[v] == EMPTY)
		{
			if (!coloring(v, next_color))
				return false;
		}

	}

	return true;
}

int main(void)
{
	int t = 0, n, m;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;

next_test:

	cin >> N;
	for (n = 1; n <= N; n++)
	{
		color[n] = EMPTY;
		hates_cnt[n] = 0;
	}

	cin >> M;
	nr_hates = 0;
	for (m = 1; m <= M; m++)
	{
		int u, v;
		cin >> u >> v;

		hates[nr_hates++] = {u, v};
		hates_cnt[u]++;
		hates[nr_hates++] = {v, u};
		hates_cnt[v]++;
	}

	sort(&hates[0], &hates[nr_hates], cmp);

	hates_cnt[0] = 0;
	for (n = 1; n <= N; n++)
		hates_cnt[n] += hates_cnt[n-1];

	bool ok = true;

	for (n = 1; n <= N; n++)
	{
		if (color[n] == EMPTY)
		{
			ok = coloring(n, RED);
			
			if (!ok)
				break;
		}
	}
	
	if (ok)
		cout << "YES\n";
	else
		cout << "NO\n";

	if (++t < T)
		goto next_test;

	return 0;
}


