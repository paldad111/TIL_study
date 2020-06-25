#include <iostream>

using namespace std;

int ntest;
int len1, seq1[50+1];
int len2, seq2[50+1];
int maxlen[50+1][50+1];

int main(void)
{
	int i, j, k, submax, glomax, test;

	cin >> ntest;

	for (test = 1; test <= ntest; test++)
	{
		cin >> len1;
		cin >> len2;

		for (i = 1; i <= len1; i++)
			cin >> seq1[i];

		for (i = 1; i <= len2; i++)
			cin >> seq2[i];

		/* base condition */
		maxlen[0][0] = 0;

		/* LIS for seq1 */
		for (i = 1; i <= len1; i++)
		{
			submax = 0;
			for (j = 0; j < i; j++)
			{
				if (j == 0 || seq1[i] > seq1[j])
					submax = max(submax, maxlen[j][0]);
			}
			maxlen[i][0] = submax + 1;
		}

		/* LIS for seq2 */
		for (i = 1; i <= len2; i++)
		{
			submax = 0;
			for (j = 0; j < i; j++)
			{
				if (j == 0 || seq2[i] > seq2[j])
					submax = max(submax, maxlen[0][j]);
			}
			maxlen[0][i] = submax + 1;
		}

#if 0
		         0  1  2  3  4  5
		       -------------------
		         x  3  4  5  7  2
		       +------------------
		0 | x  | 0  1  2  3  4  1
		  |    |
		1 | 6  | 1  
		  |    |
		2 | 4  | 1
		  |    |
		3 | 8  | 2
		  |    |
		4 | 9  | 3
		  |    |
		5 | 1  | 1

		         0  1  2  3  4  5
		       -------------------
		         x  3  4  5  7  2
		       +------------------
		0 | x  | 0  1  2  3  4  1
		  |    |
		1 | 6  | 1  2  3  4  5  2
		  |    |
		2 | 4  | 1  2  2  3  4  2
		  |    |
		3 | 8  | 2  3  4  5  6  3
		  |    |
		4 | 9  | 3  4  5  6  7  4
		  |    |
		5 | 1  | 1  2  3  4  5  2
#endif


		/* JLIS */
		glomax = -1;
		for (i = 1; i <= len1; i++)
		{
			for (j = 1; j <= len2; j++)
			{

				submax = 0;

				/**
				 * maxlen[i][j] 는 j 는 이미 선택했고,
				 * i 를 선택하는 경우이다
				 * */
				if (seq1[i] > seq2[j])
				{
					/* j 를 고정시킨다. */
					for (k = 0; k < i; k++)
					{
						if (seq1[i] > seq1[k])
							submax = max(submax, maxlen[k][j] + 1);
					}

					goto next;
				}

				/**
				 * maxlen[i][j] 는 i 는 이미 선택했고,
				 * j 를 선택하는 경우이다
				 * */
				if (seq1[i] < seq2[j])
				{
					/* i 를 고정시킨다. */
					for (k = 0; k < j; k++)
					{
						if (seq2[j] > seq2[k])
							submax = max(submax, maxlen[i][k] + 1);
					}
					goto next;
				}

next:

				maxlen[i][j] = submax;

				glomax = max(glomax, maxlen[i][j]);
			}
		}

		cout << glomax << endl;
	}


	return 0;
}
