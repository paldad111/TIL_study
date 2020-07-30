#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define MAX_LENGTH (100000)

int N, K;
bool visit[MAX_LENGTH+1];
int cost[MAX_LENGTH+1];

int main(void)
{
	queue<int> queue;

	cin.tie();
	ios::sync_with_stdio(false);

	cin >> N >> K;

	queue.push(N);
	visit[N] = true;
	cost[N] = 0;

	while (queue.size() != 0)
	{
		int n = queue.front();
		queue.pop();

		/* n -> n+1 */
		if (n+1 <= MAX_LENGTH && !visit[n+1])
		{
			cost[n+1] = cost[n] + 1;

			if (n+1 == K)
				break;

			visit[n+1] = true;
			queue.push(n+1);
		}

		/* n -> n-1 */
		if (n-1 >= 0 && !visit[n-1])
		{
			cost[n-1] = cost[n] + 1;

			if (n-1 == K)
				break;

			visit[n-1] = true;
			queue.push(n-1);
		}

		/* n -> n*2 */
		if (n*2 <= MAX_LENGTH && !visit[n*2])
		{
			cost[n*2] = cost[n] + 1;

			if (n*2 == K)
				break;

			visit[n*2] = true;
			queue.push(n*2);
		}
	}

	cout << cost[K] << "\n";

	return 0;
}
