#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct edge
{
	int f, t;
};

int V, E, NTEST;

struct edge adjs[400000+1];

int nr_edges;
int adjs_cnt[20000+1];

bool cmp(struct edge a, struct edge b)
{
	if (a.f != b.f)
		return a.f < b.f;
	else
		return a.t < b.t;
}

#define node_for_each(snode, dnode, iter)			\
	for (iter = (snode == 0 ? 0 : adjs_cnt[snode-1]),	\
			dnode = adjs[iter].t;			\
			iter < adjs_cnt[snode];			\
			dnode = adjs[++iter].t)

inline int node_adjs(int snode)
{
	return adjs_cnt[snode] - (snode == 0 ? 0 : adjs_cnt[snode-1]);
}

#define EMPTY (0)
#define RED   (1)
#define BLUE  (2)

int node_color[20000+1];

bool check_bipartite(int snode, int color)
{
	int dnode, iter, next_color;

	node_color[snode] = color;

	next_color = (color == RED ? BLUE : RED);

	node_for_each(snode, dnode, iter)
	{
		if (node_color[dnode] == EMPTY)
		{
			if (!check_bipartite(dnode, next_color))
				return false;
		}
		else
		{
			/* 같은 색이 인접, 이분 그래프가 아님 */
			if (node_color[dnode] == color)
				return false;
		}
	}

	return true;
}

int main(void)
{
	int v, e, test;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> NTEST;

	for (test = 1; test <= NTEST; test++)
	{
		cin >> V >> E;

		nr_edges = 0;
		memset(adjs_cnt, 0, sizeof(adjs_cnt));

		adjs_cnt[0] = 0;
		for (e = 0; e < E; e++)
		{
			int f, t;

			cin >> f >> t;

			adjs[nr_edges++] = {f, t};
			adjs_cnt[f]++;

			adjs[nr_edges++] = {t, f};
			adjs_cnt[t]++;
		}

		/* 인접배열 생성 */
		sort(&adjs[0], &adjs[nr_edges], cmp);

		for (v = 1; v <= V; v++)
			adjs_cnt[v] = adjs_cnt[v-1] + adjs_cnt[v];

		/* 컬러링을 통한 이분 그래프 판정 */
		memset(node_color, 0, sizeof(node_color));

		bool ok = true;

		for (v = 1; v <= V; v++)
		{
			if (node_color[v] == EMPTY)
			{
				ok = check_bipartite(v, RED);

				if (!ok)
					break;
			}
		}

		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";

	}

	return 0;
}

