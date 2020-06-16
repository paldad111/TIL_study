#include <iostream>

using namespace std;

int nrNum;
int nums[100000];
int contigSum[100000];
int maxContigSum = 0x80000000; /* INT_MIN */

int main()
{
	cin >> nrNum;

	for (int i = 0; i < nrNum; i++)
	{
		cin >> nums[i];
	}

	/* base condition */
	for (int i = 0; i < nrNum; i++)
	{
		contigSum[i] = nums[i];

		maxContigSum = max(maxContigSum, contigSum[i]);
	}

	for (int i = 1; i < nrNum; i++)
	{
		int includePrev, excludePrev;

		excludePrev = nums[i];

		contigSum[i] = max(includePrev, excludePrev);

		maxContigSum = max(maxContigSum, contigSum[i]);
	}

	cout << maxContigSum << endl;

	return 0;
}
