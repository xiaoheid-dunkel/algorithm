#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &vec, int low, int high, int mid) {
	// �������ĸ����ռ䣬�洢�ϲ������������������
	vector<int> tmp;
	tmp.reserve(high - low + 1);  // reserve resize
	int i = low;  // [low, mid]
	int j = mid + 1; // [mid+1, high]

	while (i <= mid && j <= high) {
		if (vec[i] > vec[j]) {
			tmp.push_back(vec[j++]);
		}
		else {
			tmp.push_back(vec[i++]);
		}
	}

	while (i <= mid) {
		tmp.push_back(vec[i++]);
	}

	while (j <= high) {
		tmp.push_back(vec[j++]);
	}

	// tmp�����Ԫ�� =�� ����vec����
	for (int k = low; k <= high; ++k) {
		vec[k] = tmp[k - low];
	}
}
// �����㷨Ӧ�� - �鲢����
void mergeSort(vector<int> &vec, int i, int j) {
	if (i >= j) { // �����⻮�ֵ�һ��Ԫ�ص�ʱ�򣬾ʹ���������Ľ�����֪����
		return;
	}
	int mid = (i + j) / 2;
	// �Ȼ��������⣬���������ģ
	mergeSort(vec, i, mid);
	mergeSort(vec, mid + 1, j);

	// ���ϻ��ݣ����ݵĹ����У��ϲ�������Ľ�
	merge(vec, i, j, mid);  // [i,mid] [mid+i, j]
}
int main4()
{
	vector<int> vec;
	for (int i = 0; i < 11; ++i) {
		vec.push_back(rand() % 100);
	}

	for (int v : vec) {
		cout << v << " ";
	}
	cout << endl;

	mergeSort(vec, 0, vec.size() - 1);
	for (int v : vec) {
		cout << v << " ";
	}
	cout << endl;

	return 0;
}