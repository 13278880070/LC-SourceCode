#include <iostream>
#include <queue>
#include <list>

using namespace std;

// 邻接表实现有向无环图. DAG
class Graph {
private:
	int v;		// 顶点个数
	list<int> *adj;		// 邻接表项
	int *indegree;		// 每个顶点入度
	int count;			// 图中剩余顶点数

	queue<int> graphq;		// 存储入度为 0 的顶点

public:
	Graph(int v) {
		this->v = v;
		this->count = v;
		adj = new list<int>[v];
		indegree = new int[v];

		for(int i = 0; i < v; i++) {
			indegree[i] = 0;
		}
	}

	// 添加 a -> b 的边
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		indegree[b]++;
	}

	// 拓扑排序
	bool getSort(vector<int> &vec) {
		for(int i = 0; i < v; i++) {
			if(!indegree[i]) graphq.push(i);
		}

		while (!graphq.empty()) {
			int x = graphq.front();
			graphq.pop();
			vec.push_back(x);
			count--;

			for(int ele : adj[x]) {
				indegree[ele]--;
				if(!indegree[ele]) graphq.push(ele);
			}
		}

		return !count;
	}
};

int main()
{
	Graph graph = Graph(5);
	graph.addEdge(0, 1);
	graph.addEdge(0, 3);
	graph.addEdge(1, 3);
	graph.addEdge(1, 2);
	graph.addEdge(2, 4);
	graph.addEdge(3, 2);
	graph.addEdge(3, 4);

	vector<int> vec;
	graph.getSort(vec);

	for(int ele : vec) cout<<ele<<" ";
}