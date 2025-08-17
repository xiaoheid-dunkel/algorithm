#include <iostream>
#include <vector>
using namespace std;

using uint = unsigned int;
const uint INF = INT_MAX;

int main()
{
	vector<vector<uint>> graph =
	{
		{0, 6, 3, INF, INF, INF},
		{6, 0, 2, 5, INF, INF},
		{3, 2, 0, 3, 4, INF},
		{INF, 5, 3, 0, 2, 3},
		{INF, INF, 4, 2, 0, 5},
		{INF, INF, INF, 3, 5, 0},
	};

	// һ�ΰ�ÿһ���������
	for (int k = 0; k < graph.size(); k++)
	{
		// ����Ҫ�����ڽӾ���
		for (int i = 0; i < graph.size(); i++)
		{
			for (int j = 0; j < graph.size(); j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
			}
		}
	}

	for (auto line : graph)
	{
		for (auto dis : line)
		{
			cout << dis << " ";
		}
		cout << endl;
	}

	// cout << graph[start][end] << endl;
}