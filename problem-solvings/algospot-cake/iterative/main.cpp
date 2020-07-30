#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int ncake;
int spending[40+1];
int threebake[40+1][40+1][40+1][3];

int max3(int a, int b, int c)
{
	return max(a, max(b, c));
}

int min3(int a, int b, int c)
{
	return min(a, min(b, c));
}

int main(void)
{
	int i, j, k, n, glomin;

	cin.tie(0);
	ios::sync_with_stdio(false);

	while (true)
	{
		cin >> ncake;

		if (ncake == 0)
			break;

		for (n = 1; n <= ncake; n++)
			cin >> spending[n];

		/* base condition */
		memset(threebake, 0, sizeof(threebake));

		glomin = INT_MAX;
		for (i = 0; i <= ncake; i++)
		{
			for (j = 0; j <= ncake; j++)
			{
				for (k = 0; k <= ncake; k++)
				{
					int next, sum, psum;

					next = max3(i, j, k) + 1;

					if (next > ncake)
						continue;

					if ((i != 0 && j != 0 && i == j) ||
					    (i != 0 && k != 0 && i == k) ||
					    (j != 0 && k != 0 && j == k))
						continue;

					printf("%d, %d, %d - %d %d %d\n", i, j, k,
							threebake[i][j][k][0],
							threebake[i][j][k][1],
							threebake[i][j][k][2]
							);

					/* put oven 1 */
					psum = max3(threebake[i][j][k][0] + spending[next],
						    threebake[i][j][k][1],
						    threebake[i][j][k][2]);

					sum = max3(threebake[next][j][k][0],
						   threebake[next][j][k][1],
						   threebake[next][j][k][2]);

					if (sum == 0 || sum > psum)
					{
						threebake[next][j][k][0] = threebake[i][j][k][0] + spending[next];
						threebake[next][j][k][1] = threebake[i][j][k][1];
						threebake[next][j][k][2] = threebake[i][j][k][2];

						if (next == ncake)
						{
							if (psum < glomin)
							{
								glomin = psum;
							}
						}
					}

					/* put oven 2 */
					psum = max3(threebake[i][j][k][0],
						    threebake[i][j][k][1] + spending[next],
						    threebake[i][j][k][2]);

					sum = max3(threebake[i][next][k][0],
						   threebake[i][next][k][1],
						   threebake[i][next][k][2]);

					if (sum == 0 || sum > psum)
					{
						threebake[i][next][k][0] = threebake[i][j][k][0];
						threebake[i][next][k][1] = threebake[i][j][k][1] + spending[next];
						threebake[i][next][k][2] = threebake[i][j][k][2];

						if (next == ncake)
						{
							if (psum < glomin)
							{
								glomin = psum;
							}
						}
					}

					/* put oven 3 */
					psum = max3(threebake[i][j][k][0],
						    threebake[i][j][k][1],
						    threebake[i][j][k][2] + spending[next]);

					sum = max3(threebake[i][j][next][0],
						   threebake[i][j][next][1],
						   threebake[i][j][next][2]);

					if (sum == 0 || sum > psum)
					{
						threebake[i][j][next][0] = threebake[i][j][k][0];
						threebake[i][j][next][1] = threebake[i][j][k][1];
						threebake[i][j][next][2] = threebake[i][j][k][2] + spending[next];

						if (next == ncake)
						{
							if (psum < glomin)
							{
								glomin = psum;
							}
						}
					}
				}
			}
		}

		cout << glomin << "\n";
	}

	return 0;
}
