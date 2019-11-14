// 邻接表实现有向无环图. DAG
class Graph {
private:
	int v;		// 顶点个数
	list<int> *adj;		// 邻接表项
	int *indegree;		// 每个顶点入度
	int count;			// 拓扑排序中已处理顶点数.

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
	void addDegree(int a, int b) {
		adj[a].push_back(b);
		indegree[b]++;
	}

	// 拓扑排序
	bool getsortGraph() {
		count = 0;
		for(int i = 0; i < v; i++) {
			if(!indegree[i]) graphq.push(i);
		}

		while (!graphq.empty()) {
			int x = graphq.front();
			graphq.pop();
			count++;

			for(int ele : adj[x]) {
				indegree[ele]--;
				if(!indegree[ele]) graphq.push(ele);
			}
		}

		return count == v;
	}
};

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    	Graph graph = Graph(numCourses);

    	for(vector<int> vec : prerequisites) {
    		graph.addDegree(vec[1], vec[0]);
    	}

    	return graph.getsortGraph();
    }
};