#include <iostream>

using namespace std;

int N, M;

int mat[500+1+3][500+1+3];

struct shape
{
	int w;
	int h;
	int lo[4][4];
};

#if 0
struct shape shapes[] =
{
	/*
	 * xxxx
	 */
	{
		.w = 2,
		.h = 3,
		.lo = {{0, 1},
		       {1, 1},
		       {0, 1}},
	},
};

#else
struct shape shapes[] =
{
	/*
	 * xxxx
	 */
	{
		.w = 4,
		.h = 1,
		.lo = {1, 1, 1, 1},
	},

	/*
	 * x
	 * x
	 * x
	 * x
	 */
	{
		.w = 1,
		.h = 4,
		.lo = {{1},
		       {1},
		       {1},
		       {1}},
	},

	/*
	 * xx
	 * xx
	 */
	{
		.w = 2,
		.h = 2,
		.lo = {{1, 1},
		       {1, 1}},
	},

	/*
	 * x
	 * x
	 * xx
	 */
	{
		.w = 2,
		.h = 3,
		.lo = {{1},
		       {1},
		       {1, 1}},
	},

	/*
	 * xxx
	 * x
	 */
	{
		.w = 3,
		.h = 2,
		.lo = {{1, 1, 1},
		       {1, 0, 0}},
	},

	/*
	 * xx
	 *  x
	 *  x
	 */
	{
		.w = 2,
		.h = 3,
		.lo = {{1, 1},
		       {0 ,1},
		       {0, 1}},
	},

	/*
	 *   x
	 * xxx
	 */
	{
		.w = 3,
		.h = 2,
		.lo = {{0, 0, 1},
		       {1, 1, 1}},
	},

	/*
	 *  x
	 *  x
	 * xx
	 */
	{
		.w = 2,
		.h = 3,
		.lo = {{0, 1},
		       {0, 1},
		       {1, 1}},
	},

	/*
	 * x
	 * xxx
	 */
	{
		.w = 3,
		.h = 2,
		.lo = {{1, 0, 0},
		       {1, 1, 1}},
	},

	/*
	 * xx
	 * x
	 * x
	 */
	{
		.w = 2,
		.h = 3,
		.lo = {{1, 1},
		       {1 ,0},
		       {1, 0}},
	},

	/*
	 * xxx
	 *   x
	 */
	{
		.w = 3,
		.h = 2,
		.lo = {{1, 1, 1},
		       {0, 0, 1}},
	},

	/*
	 * x
	 * xx
	 *  x
	 */
	{
		.w = 2,
		.h = 3,
		.lo = {{1, 0},
		       {1, 1},
		       {0, 1}},
	},

	/*
	 *  xx
	 * xx
	 */
	{
		.w = 3,
		.h = 2,
		.lo = {{0, 1, 1},
		       {1, 1, 0}},
	},

	/*
	 *  x
	 * xx
	 * x
	 */
	{
		.w = 2,
		.h = 3,
		.lo = {{0, 1},
		       {1, 1},
		       {1, 0}},
	},

	/*
	 * xx
	 *  xx
	 */
	{
		.w = 3,
		.h = 2,
		.lo = {{1, 1, 0},
		       {0, 1, 1}},
	},

	/*
	 * xxx
	 *  x
	 */
	{
		.w = 3,
		.h = 2,
		.lo = {{1, 1, 1},
		       {0, 1, 0}},
	},

	/*
	 *  x
	 * xx
	 *  x
	 */
	{
		.w = 2,
		.h = 3,
		.lo = {{0, 1},
		       {1, 1},
		       {0, 1}},
	},

	/*
	 *  x
	 * xxx
	 */
	{
		.w = 3,
		.h = 2,
		.lo = {{0, 1, 0},
		       {1, 1, 1}},
	},

	/*
	 * x
	 * xx
	 * x
	 */
	{
		.w = 2,
		.h = 3,
		.lo = {{1, 0},
		       {1, 1},
		       {1, 0}},
	},
};
#endif

int main(void)
{
	int n, m, s, i, j, maxima;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (n = 1; n <= N; n++)
	{
		for (m = 1; m <= M; m++)
		{
			cin >> mat[n][m];
		}
	}

	maxima = 0;

	for (n = 1; n <= N; n++)
	{
		for (m = 1; m <= M; m++)
		{
			for (s = 0; s < sizeof(shapes) / sizeof(shapes[0]); s++)
			{
				int tilesum = 0;

				for (i = 0; i < shapes[s].h; i++)
				{
					for (j = 0; j < shapes[s].w; j++)
					{
						if (shapes[s].lo[i][j] == 1)
							tilesum += mat[n+i][m+j];
					}
				}

				maxima = max(maxima, tilesum);

			}
		}
	}

	cout << maxima << "\n";

	return 0;
}
