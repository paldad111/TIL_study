#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, K;
int V[150+1];

int count_eq_k(int *arr)
{
	int s = 1, e = 1, cnt = 0, arraysum = V[1];

	while (s <= N && e <= N)
	{
		
		if (arraysum < K)
		{
			cnt += e - s + 1;

			e++;

			if (e <= N)
				arraysum += V[e];
		}
		else
		{
			arraysum -= V[s];

			if (s == e)
				e++;
			s++;
		}


	}

	return cnt;
}

int main(void)
{
	int n;

	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;

	for (n = 1; n <= N; n++)
		cin >> V[n];

	cout << count_eq_k(V) << "\n";

	return 0;
}
