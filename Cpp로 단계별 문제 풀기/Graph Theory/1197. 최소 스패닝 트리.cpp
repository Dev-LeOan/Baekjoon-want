#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parents[10001]; //������ �ִ� ������ 10000���̹Ƿ� �θ� �迭�� 10001��ŭ ����� ���´�.
class Edge
{
public:
	int node[2];
	int weight;
	Edge(int a, int b, int weight)
	{
		node[0] = a;
		node[1] = b;
		this->weight = weight;
	}
	bool operator<(Edge& edge)
	{
		return this->weight < edge.weight;
	}
};
int getParents(int node)
{
	if (parents[node] == node) return node; //�ڱ� �ڽ��� �θ��̸� �״�� ��ȯ
	return getParents(parents[node]);       // �ڱ� �ڽ��� �θ��� ��尡 ���� ������ ��������� �Լ� ���� (���� �θ� ��尡 ���´�)
}
void unionParent(int node1, int node2)
{
	node1 = getParents(node1);
	node2 = getParents(node2);
	if (node1 < node2) parents[node2] = node1;   // �� ��� �� ���� ���� �θ�� ����
	else parents[node1] = node2;
}
bool isCycle(int node1, int node2)
{
	node1 = getParents(node1);
	node2 = getParents(node2);
	if (node1 == node2) return true;
	else return false;
}
int main()
{
	vector<Edge> E; //
	int n, v;  //���� n�� ���� v
	cin >> n >> v;
	int a, b, c; // ���� a�� ���� b�� ����ġ c�� ����Ǿ� �ִ�.
	for (int i = 0; i < v; i++)
	{
		cin >> a >> b >> c;
		E.push_back(Edge(a, b, c));
	}
	sort(E.begin(), E.end()); //������ ������������ ���� ( weight ũ�⸦ ������������ ����, ������ MST�� ���� �ͺ��� Ž���ϱ� ����

	for (int i = 0; i <= n; i++) //��� ������ŭ �ڱ� �ڽ��� �θ�� �ʱ�ȭ ���ѳ��� (Union & Find�� ���ؼ�)
	{
		parents[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < E.size(); i++)
	{
		if (!isCycle(E[i].node[0], E[i].node[1]))
		{
			sum += E[i].weight;
			unionParent(E[i].node[0], E[i].node[1]);
		}
	}
	cout << sum << endl;
	return 0;
}