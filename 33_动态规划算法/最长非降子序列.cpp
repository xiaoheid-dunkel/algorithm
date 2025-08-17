
#include <iostream>
#include <algorithm>
using namespace std;

/*
���ؽⷨ����һ���õ����Ž⣬��Ч�Ľⷨ     Ҫ���㷨ʱ�临�Ӷȣ�O(n^2)
LIS���⣺�����е���ǽ������������еĳ���
5 3 4 1 8 7 9
״̬��dp[i] �Ե�i��Ԫ�ؽ�β�ķǽ������еĳ���
״̬ת�Ʒ��̣�
dp[0] = 1
dp[1] = max{1,  1 + dp[0]} ar[0] <= ar[1] = 1
dp[2] = max{1,  1 + dp[1]}   ar[1] <= ar[2] = 2
...
dp[i] = max{1, 1 + dp[j]}  ������ar[j] <= ar[i]  j��λԪ�غ�i��λԪ�ز��ܹ��ɷǽ�������
*/
int main4()
{
	int ar[] = { 5, 3, 4, 1, 8, 6, 7, 10 };
	const int n = sizeof(ar) / sizeof(ar[0]);
	int dp[n] = { 0 };
	int maxval = 0;
	
	for (int i = 0; i < n; ++i) {  // O(n)
		dp[i] = 1;
		for (int j = 0; j < i; ++j) {  // O(n)
			if (ar[j] <= ar[i] && 1 + dp[j] > dp[i]) {
				dp[i] = 1 + dp[j];
			}
		}

		if (dp[i] > maxval) {
			maxval = dp[i];
		}
	}

	cout << maxval << endl;  // 4

	return 0;
}