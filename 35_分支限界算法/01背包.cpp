
#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

// ��֧�޽��㷨 - 01��������  ���ȼ�����
int w[] = { 16,15,15 }; // ��Ʒ������
int v[] = { 45, 25, 25 }; // ��Ʒ�ļ�ֵ
int c = 31; // ����������
const int n = sizeof(w) / sizeof(w[0]); // ��Ʒ�ĸ���
int cw = 0; // ��ѡ����Ʒ������
int cv = 0; // ��ѡ����Ʒ�ļ�ֵ
int bestv = 0; // װ�뱳������Ʒ�����ż�ֵ

// �����ڵ�����
struct Node {
	Node(int w, int v, int l, int up, Node *p, bool left) {
		weight = w;
		value = v;
		level = l;
		parent = p;
		isleft = left;
		upbound = up;
	}
	int weight; // ��ѡ����Ʒ��������
	int value; // ��ѡ����Ʒ���ܼ�ֵ
	int level; // �ڵ����ڵĲ���
	Node *parent; // ��¼���ڵ�
	bool isleft; // �ڵ��Ƿ�ѡ��
	int upbound; // �ڵ�ļ�ֵ�Ͻ磬 ������ڵ����£������ѡ�����Ʒ�������ܼ�ֵ
};
// queue<Node*> que; // ��ȱ�����Ҫ��FIFO����
priority_queue<Node*, vector<Node*>, function<bool(Node*, Node*)>> que([](Node*n1, Node*n2)->bool {
	return n1->upbound < n2->upbound;
});

void addLiveNode(int w, int v, int l, int up, Node *parent, bool isleft) {
	Node *node = new Node(w, v, l, up, parent, isleft);
	que.push(node);

	// �����ȼ����оͲ��ñ�ǲ������Ž��Ҷ�ӽڵ��ˣ���Ϊ���ȼ����е���ĳһ��Ҷ�ӽڵ�ʱ������ֵ�Ͳ�����
	/*if (l == n && v == bestv) {
		bestnode = node;
	}*/
}
// ���ֵ�Ͻ�
int maxBound(int i) {
	int bound = cv;
	for (int level = i; level < n; ++level) {
		bound += v[level];
	}
	return bound;
}
int main()
{
	int i = 0; // ��ʼ�Ĳ���
	Node *node = nullptr; // ��¼���ڵ�
	int upbound = maxBound(0);
	while (i < n) {
		// ѡ����Ʒi
		int wt = cw + w[i];
		if (wt <= c) {
			if (cv + v[i] > bestv) {
				bestv = cv + v[i];
			}

			// �����Ӽ��������е���
			addLiveNode(cw + w[i], cv + v[i], i + 1, upbound, node, true);
		}

		// ��ѡ����Ʒi
		upbound = maxBound(i+1); // i+1��ʾ��һ��δ���������Ʒ�������±�
		if (upbound >= bestv) {
			addLiveNode(cw, cv, i + 1, upbound, node, false);
		}

		node = que.top();
		que.pop();
		i = node->level;
		cw = node->weight;
		cv = node->value;
		upbound = node->upbound;
	}

	cout << bestv << endl;
	int x[n] = { 0 };
	for (int j = n - 1; j >= 0; --j) {
		x[j] = node->isleft ? 1 : 0;
		node = node->parent;
	}

	for (int v : x) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}

#if 0
// ��֧�޽��㷨 - 01��������     FIFO���� 
int w[] = { 16,15,15 }; // ��Ʒ������
int v[] = { 45, 25, 25 }; // ��Ʒ�ļ�ֵ
int c = 30; // ����������
const int n = sizeof(w) / sizeof(w[0]); // ��Ʒ�ĸ���
int cw = 0; // ��ѡ����Ʒ������
int cv = 0; // ��ѡ����Ʒ�ļ�ֵ
int bestv = 0; // װ�뱳������Ʒ�����ż�ֵ

// �����ڵ�����
struct Node {
	Node(int w, int v, int l, Node *p, bool left) {
		weight = w;
		value = v;
		level = l;
		parent = p;
		isleft = left;
	}
	int weight; // ��ѡ����Ʒ��������
	int value; // ��ѡ����Ʒ���ܼ�ֵ
	int level; // �ڵ����ڵĲ���
	Node *parent; // ��¼���ڵ�
	bool isleft; // �ڵ��Ƿ�ѡ��
};
Node *bestnode = nullptr; // ��¼���Ž��Ҷ�ӽڵ�
queue<Node*> que; // ��ȱ�����Ҫ��FIFO����

void addLiveNode(int w, int v, int l, Node *parent, bool isleft) {
	Node *node = new Node(w, v, l, parent, isleft);
	que.push(node);

	if (l == n && v == bestv) {
		bestnode = node;
	}
}
// ���ֵ�Ͻ�
int maxBound(int i) {
	int bound = 0;
	for (int level = i + 1; level < n; ++level) {
		bound += v[level];
	}
	return bound;
}
int main()
{
	int i = 0; // ��ʼ�Ĳ���
	Node *node = nullptr; // ��¼���ڵ�
	while (i < n) {
		// ѡ����Ʒi
		int wt = cw + w[i];
		if (wt <= c) {
			if (cv + v[i] > bestv) {
				bestv = cv + v[i];
			}

			// �����Ӽ��������е���
			addLiveNode(cw+w[i], cv+v[i], i+1, node, true);
		}

		// ��ѡ����Ʒi
		int upbound = maxBound(i);
		if (cv + upbound >= bestv) {
			addLiveNode(cw, cv, i + 1, node, false);
		}
		
		node = que.front();
		que.pop();
		i = node->level;
		cw = node->weight;
		cv = node->value;
	}

	cout << bestv << endl;
	int x[n] = { 0 };
	for (int j = n - 1; j >= 0; --j) {
		x[j] = bestnode->isleft ? 1 : 0;
		bestnode = bestnode->parent;
	}

	for (int v : x) {
		cout << v << " ";
	}
	cout << endl;
	return 0;
}
#endif