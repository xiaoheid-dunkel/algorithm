#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���Ż��ֺ�����������׼��
int partation(vector<int> &vec, int i, int j) {
	int val = vec[i]; // ��Ϊ��׼��
	int l = i;
	int r = j;
	while (l < r) {
		while (l < r && vec[r] >= val) { // �� - ��  �ҵ�һ����valС��
			r--;
		}
		if (l < r) {
			vec[l++] = vec[r];
		}
		while (l < r && vec[l] < val) { // �� - ��  �ҵ�һ����val���
			l++;
		}
		if (l < r) {
			vec[r--] = vec[l];
		}
	}
	vec[l] = val;  // ���û�׼��
	return l; // ���ػ�׼�����±�
}
void quickSort(vector<int> &vec, int i, int j) {
	if (i >= j) {
		return;
	}
	int pos = partation(vec, i, j);
	quickSort(vec, i, pos - 1);
	quickSort(vec, pos + 1, j);
}
int main2()
{
	vector<int> vec;
	for (int i = 0; i < 11; ++i) {
		vec.push_back(rand() % 100);
	}
	
	for (int v : vec) {
		cout << v << " ";
	}
	cout << endl;

	quickSort(vec, 0, vec.size() - 1);
	for (int v : vec) {
		cout << v << " ";
	}

	cout << endl;

	return 0;
}