
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*
LCS�����������е�����������еĳ���   �Ӵ��������ģ�
helloworld
   hlweord

helloworl  hlweord   => ���1
helloworlr  hlweor    => ���2

X : X1,X2...Xn
Y:  Y1,Y2...Ym

״̬��ת�Ʒ���
���Xn == Ym
dp(X[1...n],Y[1...m]) = dp(X[1...n-1], Y[1...m-1]) + 1
���Xn != Ym
dp(X[1...n],Y[1...m]) = max{dp(X[1...n],Y[1...m-1]) ,  dp(X[1...n-1],Y[1...m]) }

״̬���������������е�LCS�ĳ���
dp[n][m] : n��ʾ��һ�����ĳ���   m��ʾ�ڶ������ĳ��ȣ�n��m��Ԫ�ص�ֵ����¼�ľ�������������LCS����
*/
static int cnt = 0; // ���ڴ������

string str1 = "helloworld";
string str2 = "hlweord";
int **dp = nullptr;
int **path = nullptr; // ��¼�������

#if 0
// �ݹ�ʵ��
int LCS(string X, int n, string Y, int m) {
	if (n < 0 || m < 0) {
		return 0;
	}

	if (dp[n][m] >= 0) {  // �����������Ľ��Ƿ����
		return dp[n][m];
	}

	cnt++; // �����㷨��628��    ��̬�滮��40

	if (X[n] == Y[m]) {
		dp[n][m] = LCS01(X, n - 1, Y, m - 1) + 1;
		path[n][m] = 1;  // n,m  => n-1,m-1  �Խ���
		return dp[n][m];
	}
	else {
		int len1 = LCS01(X, n, Y, m - 1);
		int len2 = LCS01(X, n - 1, Y, m);
		if (len1 >= len2) {
			dp[n][m] = len1;
			path[n][m] = 2; // n,m => n,m-1  ���
		}
		else {
			dp[n][m] = len2;
			path[n][m] = 3; // n,m => n-1,m   �Ϸ�
		}
		return dp[n][m];
	}
}
#endif

// �ǵݹ�ʵ��
int LCS(string X, int i, string Y, int j) {
	for (int n = 1; n <= i+1; ++n) {
		for (int m = 1; m <= j+1; ++m) {
			if (X[n-1] == Y[m-1]) {
				dp[n][m] = 1 + dp[n - 1][m - 1];  // n==0 m ==0
				path[n][m] = 1;
			}
			else {
				int len1 = dp[n-1][m]; // ������
				int len2 = dp[n][m-1]; // �����
				if (len1 >= len2) {
					dp[n][m] = len1;
					path[n][m] = 3;
				} 
				else {
					dp[n][m] = len2;
					path[n][m] = 2;
				}
			}
		}
	}
	return dp[i+1][j+1];
}

void backStrace(string str1, int n, int m) {
	if (n <= 0 || m <= 0) {
		return;
	}

	if (path[n][m] == 1) {  // ��Ӧλ�õ�Ԫ������ȵ�
		backStrace(str1, n - 1, m - 1); // ��Խ��ߵݹ�
		cout << str1[n-1];
	}
	else {
		if (path[n][m] == 2) {
			backStrace(str1, n, m - 1);  // ����ݹ�
		}
		else {  // path[n][m] = 3
			backStrace(str1, n - 1, m); // ���ϵݹ�
		}
	}
}
int main5()
{
	// dp��һ��n��m�еĶ�ά����
	int n = str1.size();
	int m = str2.size();
	dp = new int*[n+1];   // n��
	for (int i = 0; i < n+1; ++i) {
		dp[i] = new int[m+1];  // m��
		for (int j = 0; j < m+1; ++j) {
			// dp[i][j] = -1;
			dp[i][j] = 0;
		}
	}
	path = new int*[n+1];   // n��
	for (int i = 0; i < n+1; ++i) {
		path[i] = new int[m+1]();  // m��
	}

	int size = LCS(str1, n-1, str2, m-1);
	cout << "LCS length:" << size << endl;
	cout << "cnt:" << cnt << endl;

	// backStrace(str1, n-1, m-1);
	backStrace(str1, n, m);

	//for (int i = 0; i < n; ++i) {   // ��
	//	for (int j = 0; j < m; ++j) { // ��
	//		cout << path[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	// �ͷ�dp�����ڴ�
	return 0;
}