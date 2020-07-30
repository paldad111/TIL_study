#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX_LENGTH (100000)

int N, K;
int path[MAX_LENGTH+1];
int cost[MAX_LENGTH+1];

int main(void)
{
	queue<int> queue;

	cin.tie();
	ios::sync_with_stdio(false);

	cin >> N >> K;

	queue.push(N);
	path[N] = 1;
	cost[N] = 0;

	while (queue.size() != 0)
	{
		int n = queue.front();
		queue.pop();

		/* K 로 도달하기 전의 최적경로가 모두 계산된 경우에만 종료해야 한다 */
		if (n == K)
			break;

		/* n -> n+1 */
		if (n+1 <= MAX_LENGTH)
		{
			/* 첫 확장인 경우에만 큐잉하고 비용을 계산한다. */
			if (path[n+1] == 0)
			{
				cost[n+1] = cost[n] + 1;
				queue.push(n+1);
			}

			/* 최적 경로로 들어온 경우에만 경로의 수를 더한다. */
			if (cost[n+1] == cost[n] + 1)
				path[n+1] += path[n];

		}

		/* n -> n-1 */
		if (n-1 >= 0)
		{
			/* 첫 확장인 경우에만 큐잉하고 비용을 계산한다. */
			if (path[n-1] == 0)
			{
				cost[n-1] = cost[n] + 1;
				queue.push(n-1);
			}

			/* 최적 경로로 들어온 경우에만 경로의 수를 더한다. */
			if (cost[n-1] == cost[n] + 1)
				path[n-1] += path[n];
		}

		/* n -> n*2 */
		if (n*2 <= MAX_LENGTH)
		{
			/* 첫 확장인 경우에만 큐잉하고 비용을 계산한다. */
			if (path[n*2] == 0)
			{
				cost[n*2] = cost[n] + 1;
				queue.push(n*2);
			}

			/* 최적 경로로 들어온 경우에만 경로의 수를 더한다. */
			if (cost[n*2] == cost[n] + 1)
				path[n*2] += path[n];
		}
	}

	cout << cost[K] << "\n";
	cout << path[K] << "\n";

	return 0;
}
