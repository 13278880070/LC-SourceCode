// 邻接表实现有向无环图. graph
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

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        Graph graph = Graph(numCourses);
        for(vector<int> vec : prerequisites) {
        	graph.addEdge(vec[1], vec[0]);
        }

        vector<int> retvec;
        bool re = graph.getSort(retvec);

        return re ? retvec : vector<int>{};
    }
};