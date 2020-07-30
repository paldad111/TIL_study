#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define NR_MAX (1000)

int M, N;
/* 0: 익지않음 1: 익음 -1: 없음 */
int tomato[NR_MAX+1][NR_MAX+1];

/* 최종 날짜 */
int maxday;

/* 익지 않은 토마토의 수 */
int todo;

/* 상, 우, 하, 좌 */
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

int main(void)
{
	int m, n;
	list<pair<int, int>> queue[2];
	auto &cqueue = queue[0];
	auto &nqueue = queue[1];

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> M >> N;

	todo = 0;
	maxday = 0;

	for (n = 1; n <= N; n++)
	{
		for (m = 1; m <= M; m++)
		{
			int t;
			cin >> t;
			
			tomato[n][m] = t;

			if (t == 0)
				todo++;

			if (t == 1)
				cqueue.push_back(make_pair(n, m));
		}
	}

	while (true)
	{
		int i, r, c, nr, nc;

		/* 현재 날짜에 익은 모든 토마토에 대해 확장 */
		while (cqueue.size() != 0)
		{
			tie(r, c) = cqueue.front();
			cqueue.pop_front();

			for (i = 0; i < 4; i++)
			{
				nr = r + dy[i];
				nc = c + dx[i];

				/* 범위밖 */
				if (nr < 1 || nr > N || nc < 1 || nc > M)
					continue;

				/* 토마토가 존재하지 않음 */
				if (tomato[nr][nc] == -1)
					continue;

				/* 이미 더 이른 시점에 익은 토마토임 */
				if (tomato[nr][nc] == 1)
					continue;

				/* (nr, rc) 토마토는 (r, c) 토마토에 의해 익는다 */
				tomato[nr][nc] = 1;

				/* 익지 않은 토마토의 수를 하나 감소 */
				todo--;

				/* 익은 토마토의 위치를 큐잉 */
				nqueue.push_back(make_pair(nr, nc));
			}
		}

		/* 새로 확장된 상태가 없으면 종료 */
		if (nqueue.size() == 0)
			break;

		/* 새로 확장된 상태가 있으면 날짜를 증가시키고 큐를 스왑 */
		maxday++;

		cqueue.clear();
		swap(cqueue, nqueue);
	}

	if (todo != 0)
		cout << "-1\n";
	else
		cout << maxday << "\n";

	return 0;
}

