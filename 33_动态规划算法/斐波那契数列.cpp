
#include <iostream>
#include <algorithm>
using namespace std;

/*
                           func1(5)   ������ָ��������쳲���������   ǰ����������  1  1
            func1(4)                   func1(3)  
	 func1(3)   func1(2)          func1(2)  func1(1)        
	 ��ô�������������Ž������ ��=�� �����״̬ 
	 dp[i]:쳲����������е�i�����ֵ�ֵ
*/

// ����n��ʾ쳲��������������ֵĸ�����������Ӧ������쳲������������ֵ�ֵ��
//int fabnacci(int n, int dp[]) {
//	if (dp[n] > 0) { // ������n֮ǰ��������
//		return dp[n];
//	}
//	if (n == 1 || n == 2) {
//		dp[n] = 1;
//		return 1;
//	}
//	else {
//		dp[n] = fabnacci(n - 1, dp) + fabnacci(n - 2, dp);
//		return dp[n] ;
//	}
//}
//int main()
//{
//	//  1 1 2 3 5
//	int n = 10;    
//	int *dp = new int[n + 1]();
//	int val = fabnacci(n, dp);
//	cout << val << endl;
//
//	return 0;
//}

/*
fabnacci
״̬�� dp[i] 쳲����������е�i�����ֵ�ֵ
״̬��ת�Ʒ�����:
dp[1] = 1
dp[2] = 1
dp[3] = dp[3-1] + dp[3-2] = dp[2] + dp[1] = 2
dp[i] = dp[i-1] + dp[i-2]  ������i > 2
*/
int main2()
{
	const int n = 10;
	int dp[n + 1] = {0};
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << endl;
	return 0;
}