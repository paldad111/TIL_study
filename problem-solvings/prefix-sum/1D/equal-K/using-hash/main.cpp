#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, K;
int V[150+1];

int count_eq_k(int *arr)
{
	int r, cnt = 0, presum = 0;
	unordered_map<int, int> prehash;

	for (r = 1; r <= N; r++)
	{
		/* 원소 r 까지의 prefix sum */
		presum += V[r];

		prehash[presum - V[r]]++;

		/*
		 * r < l 인 l 중에
		 * presum[l] - presum[l] = K 를 만족하는 l 이 몇개인지 찾는다.
		 */
		if (prehash.find(presum - K) != prehash.end())
			cnt += prehash[presum - K];
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
