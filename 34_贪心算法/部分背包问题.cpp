
#include <iostream>
#include <algorithm>
using namespace std;

/*
���ֱ������⣬��n�����壬��i�����������Ϊwi����ֵΪvi����������������C����������ܼ�ֵ�����ߡ�
ÿһ�����嶼����ֻȡ��һ���֣���ֵ���������������㡣������ܼ�ֵ��

̰���㷨 - 01���� - ��һ���õ����Ž�
*/
struct Product {
	double getPrice()const {
		return v * 1.0 / w;
	}
	bool operator>(const Product &p) const {
		return getPrice() > p.getPrice();
	}
	int id; // ��Ʒ��id
	int w; // ��Ʒ������
	int v; // ��Ʒ�ļ�ֵ
};
int main2()
{
	int w[] = { 8,6,4,2,5 };
	int v[] = { 6,4,7,8,6 };
	const int n = sizeof(w) / sizeof(w[0]);
	int c = 12;
	int x[n] = { 0 };

	Product pros[n];
	for (int i = 0; i < n; ++i) {
		pros[i].id = i;
		pros[i].w = w[i];
		pros[i].v = v[i];
	}

	// ����Ʒ���Լ۱Ƚ�������
	sort(pros, pros + n, [](const Product &p1, const Product &p2)->bool {return p1 > p2; });

	// ���Լ۱ȸߵ�����������ţ�ֻ���Ǿֲ������Ž⣩
	double bestv = 0.0; // ��¼����������ֵ
	for (int i = 0; i < n; ++i) {
		if (pros[i].w <= c) { // ˵����i����Ʒ����װ�뱳��
			bestv += pros[i].v;
			c -= pros[i].w;
		}
		else { // ˵����i����Ʒ�޷�ȫ��װ�뱳������ʣ�������ı���װ����Ʒ��һ����
			bestv = bestv + pros[i].v*(c*1.0 / pros[i].w);
			x[pros[i].id] = 1;
			break;
		}

		x[pros[i].id] = 1;
	}

	cout << "bestv:" << bestv << endl;
	for (int v : x) {
		cout << v << " ";
	}
	cout << endl;

	return 0;
}