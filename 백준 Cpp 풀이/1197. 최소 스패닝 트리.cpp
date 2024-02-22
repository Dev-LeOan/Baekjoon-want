#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parents[10001]; //정점의 최대 개수가 10000개이므로 부모 배열은 10001만큼 만들어 놓는다.
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
	if (parents[node] == node) return node; //자기 자신이 부모이면 그대로 반환
	return getParents(parents[node]);       // 자기 자신이 부모인 노드가 나올 때까지 재귀적으로 함수 실행 (최종 부모 노드가 나온다)
}
void unionParent(int node1, int node2)
{
	node1 = getParents(node1);
	node2 = getParents(node2);
	if (node1 < node2) parents[node2] = node1;   // 두 노드 중 작은 값을 부모로 설정
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
	int n, v;  //정점 n과 간선 v
	cin >> n >> v;
	int a, b, c; // 정점 a와 정점 b가 가중치 c로 연결되어 있다.
	for (int i = 0; i < v; i++)
	{
		cin >> a >> b >> c;
		E.push_back(Edge(a, b, c));
	}
	sort(E.begin(), E.end()); //간선을 오름차순으로 정렬 ( weight 크기를 오름차순으로 정렬, 이유는 MST는 작은 것부터 탐색하기 때문

	for (int i = 0; i <= n; i++) //노드 개수만큼 자기 자신을 부모로 초기화 시켜놓기 (Union & Find를 위해서)
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