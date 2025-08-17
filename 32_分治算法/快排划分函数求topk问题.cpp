#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���Ż��ֺ�����������׼��
static int partation(vector<int> &vec, int i, int j) {
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

// �ҵ�k��ģ�  vec.size()-k С�� �±�
int max_select_topk(vector<int> &vec, int i, int j, int k) {
	int pos = partation(vec, i, j); // pos��ʾ��׼����λ��
	if (pos == vec.size() - k) { // ��׼����λ�ú�top k��kֵ�����
		return pos;
	}
	else if (pos < vec.size() - k) { // topkӦ���ڻ�׼�����ұ�
		return max_select_topk(vec, pos + 1, j, k);
	}
	else { // topkӦ�����ڻ�׼�������
		return max_select_topk(vec, i, pos - 1, k);
	}
}
// �ҵ�kС�ģ�  k-1С�� �±�   3
int min_select_topk(vector<int> &vec, int i, int j, int k) {
	int pos = partation(vec, i, j); // pos��ʾ��׼����λ��
	if (pos == k-1) { // ��׼����λ�ú�top k��kֵ�����
		return pos;
	}
	else if (pos < k-1) { // topkӦ���ڻ�׼�����ұ�
		return min_select_topk(vec, pos + 1, j, k);
	}
	else { // topkӦ�����ڻ�׼�������
		return min_select_topk(vec, i, pos - 1, k);
	}
}
int main3()
{
	vector<int> vec;
	for (int i = 0; i < 20; ++i) {
		vec.push_back(rand() % 100);
	}

	// ���top 10���Ԫ��
	int pos = max_select_topk(vec, 0, vec.size() - 1, 4);
	cout << "��topk���:" << vec[pos] << endl;
	cout << "ǰtopk���:";
	for (int i = pos; i < vec.size(); ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;

	// ��toplС��
	pos = min_select_topk(vec, 0, vec.size() - 1, 4);
	cout << "��topkС��:" << vec[pos] << endl;
	cout << "ǰtopkС��:";
	for (int i = 0; i <= pos; ++i) {
		cout << vec[i] << " ";
	}
	cout << endl;

	sort(vec.begin(), vec.end());
	for (int v : vec) {
		cout << v << " ";
	}

	cout << endl;

	return 0;
}