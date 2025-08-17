#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// O(logn)����ʱ�������λ��
double middleValue(vector<int> &nums1, int length1, vector<int> &nums2, int length2) {
	if (length1 > length2) { // �ڶ̵������������ʵ�i��jֵ
		return middleValue(nums2, length2, nums1, length1);
	}

	if (length1 == 0) {
		// 0 0 0 0 0 0 0    (6-1)/2=3   
		int k = (length2 - 1) / 2;
		if (length2 % 2 == 0) {
			return (nums2[k] + nums2[k + 1]) * 1.0 / 2;
		}
		else {
			return nums2[k];
		}
	}

	int i = 0;
	int j = 0;
	int begin = 0;
	int end = length1;
	int k = (length1 + length2 + 1) / 2;    // 7 / 2 = 3   0 0 0 0 0 0 0
	while (begin <= end) {  // �����������㷨˼�룬����ʱ���ҵ�i+j = k
		i = (begin + end) / 2; 
		j = k - i;
		if (i > 0 && j < length2 && nums1[i - 1] > nums2[j]) {
			end = i - 1;
		}
		else if (j > 0 && i < length1 && nums2[j - 1] > nums1[i]) {
			begin = i + 1;
		}
		else {
			break; // arr[i-1] < brr[j] && brr[j-1] < arr[i]
		}
	}
	// nums1�ر�̣�����nums1�����Ԫ�ص�ֵ���ر��
	int left = 0;
	if (i == 0) {  // ��λ���϶�����num2������鵱��
		left = nums2[j - 1];
	} 
	else if (j == 0) { // nums2�������̫����  ��λ���϶�����num1������鵱��
		left = nums1[i - 1];
	}
	else {
		left = std::max(nums1[i - 1], nums2[j - 1]);
	}
	int right = 0;
	if (i == length1) { // nums1����Ԫ��̫�٣�����ֵ���ر��С   ��λ���϶�����num2������鵱��
		right = nums2[j];
	}
	else if (j == length2) { //��λ���϶�����num1������鵱��
		right = nums1[i];
	}
	else {
		right = std::min(nums1[i], nums2[j]);
	}
	// �ҵ��˺��ʵ�i��j��ֵ
	if ((length1 + length2) % 2 == 0) { // ż������
		return (left + right)*1.0 / 2;
	}
	else { // ��������
		return left;
	}
}
int main()
{
	vector<int> vec1;
	vector<int> vec2;
	//for (int i = 0; i < 10; ++i) {
	//	vec1.push_back(rand() % 100);
	//}

	for (int i = 0; i < 5; ++i) {
		vec2.push_back(rand() % 100);
	}

	vector<int> vec = vec1;
	for (int v : vec2) {
		vec.push_back(v);
	}
	sort(vec.begin(), vec.end());
	for (int v : vec) {
		cout << v << " ";
	}
	cout << endl;

	sort(vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());

	double midval = middleValue(vec1, vec1.size(), vec2, vec2.size());
	cout << "midval:" << midval << endl;

	return 0;
}