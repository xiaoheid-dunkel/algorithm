#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
// Kruskal�㷨ʵ�� - ���鼯��Ӧ��
// ������
struct Edge
{
	Edge(int s, int e, int c)
		: start(s)
		, end(e)
		, cost(c)
	{}
	int start; // ��ʼ�Ľڵ�
	int end;   // ĩβ�ڵ�
	int cost;  // �ߵ�Ȩֵ
};

const int SIZE = 1000;
int parent[SIZE];

// ���鼯 - ��ѯ�ӿ�ʵ��
int find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}

int main()
{
	for (int i = 0; i < SIZE; i++)
	{
		parent[i] = i;
	}

	// ����һ��������
	vector<Edge> edges;
	int n;
	cin >> n;

	char s, e;
	int c;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e >> c;
		// ��ȡ�ߵ���Ϣ����ӵ���������
		edges.emplace_back(s, e, c);
	}

	// ���еı߰�ȨֵС�����������
	sort(edges.begin(), edges.end(),
		[](auto& a, auto& b)->bool {
			return a.cost < b.cost;
		});

	// ��ʼѡ�ߣ���С�������ѡ��
	for (int i = 0; i < edges.size(); i++)
	{
		// ��νѡ��ߣ����Ǻϲ������ߵ��������㣬����ǰ����
		// ����������֮ǰ����һ������(����һ��������)
		int a = find(edges[i].start);
		int b = find(edges[i].end);
		if (a != b)
		{
			// ���Խ��кϲ�
			parent[a] = b;
			printf("%c -> %c cost:%d \n", edges[i].start,
				edges[i].end, edges[i].cost);
		}
	}
}
#endif