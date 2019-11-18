#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
#include <cstring>

using namespace std;

// 邻接矩阵实现
class Graph {
private:
	int vnum;
	queue<int> gqueue;
	int **graph;
	int *indegree;

	int count;		// gqueue 辅助判断是否可得到正确的拓扑排序.

public:
	Graph(int v) {
		this->vnum = v;
		graph = new int*[v];
		indegree = new int[v];

		for(int i = 0; i < v; i++) {
			graph[i] = new int[v];
			indegree[i] = 0;

			for(int j = 0; j < v; j++) graph[i][j] = 0;
		}

		this->count = v;
	}

	~Graph() {
		delete []indegree;
		for(int i = 0; i < vnum; i++) delete []graph[i];
		delete []graph;
	}

	// 添加 a->b 的边
	void addEdge(int a, int b) {
		graph[a][b] = 1;
		indegree[b]++;
	}

	// 得到拓扑排序结果
	bool getSort(vector<int>& vec) {
		int x;

		// 首先将所有入度为 0 的结点入队列
		for(int i = 0; i < vnum; i++) {
			if(!indegree[i]) gqueue.push(i);
		}

		while (!gqueue.empty()) {
			x = gqueue.front();
			gqueue.pop();

			vec.push_back(x);
			count--;
			// cout<<"x = "<<x<<endl;

			for(int i = 0; i < vnum; i++) {
				if(graph[x][i]) {
					indegree[i]--;
					if(!indegree[i]) gqueue.push(i);
				}
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
	if(!graph.getSort(vec)) {
		cout<<"error"<<endl;
	} else {
		for(int ele : vec) cout<<ele<<" ";
	}
}

