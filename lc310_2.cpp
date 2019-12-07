class Solution {	// BFS + 拓扑排序思想
public:				// 每次处理相邻结点数为 1 的点, 最后剩余结点为目标中间结点.
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

    	if(n == 1) return vector<int>{0};
        // 记录所有边入度
        vector<int> degree(n, 0);

        // 使用邻接表法, 减少内存占用.
        list<int>* graph = new list<int>[n];

        for(vector<int> v : edges) {
        	graph[v[0]].push_back(v[1]);
        	graph[v[1]].push_back(v[0]);

        	degree[v[0]]++;
        	degree[v[1]]++;
        }

        int left = n;

        // 类似拓扑
        queue<int> q;
        for(int i = 0; i < n; i++) {
        	if(degree[i] == 1) q.push(i);
        }

        int size, i, x;
        vector<int> retvec;
        while (left > 2) {
        	size = q.size();
        	for(i = 0; i < size; i++, q.pop()) {
        		x = q.front();
        		for (int ele : graph[x]) {
        			degree[ele]--;
        			if(degree[ele] == 1) q.push(ele);
        		}

        		left--;
        	}
        }

        while (!q.empty()) {
        	retvec.push_back(q.front());
        	q.pop();
        }

        return retvec;
    }
};

// 总的思想: 要求的就是整个图中最中间的结点.
// 由外往内的思想