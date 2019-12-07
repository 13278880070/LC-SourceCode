class Solution {	// 求最小高度树
public:				// 超时..
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n, vector<int>(n, 0));

        for(vector<int> v : edges) {
        	graph[v[0]][v[1]] = 1;
        	graph[v[1]][v[0]] = 1;
        }

        vector<int> retvec;
        vector<int> result(n);
        vector<bool> visit(n);

        // 对每个元素, 将其作为根节点, BFS
        queue<int> q;
        int size, depth, x, i, j, k;
        for(i = 0; i < n; i++) {
        	for(int m = 0; m < n; m++) visit[m] = false;
        	q.push(i);
        	depth = 0;
        	visit[i] = true;
        	while (!q.empty()) {	// 对每个 i 进行 BFS
        		depth++;
        		size = q.size();
        		for(j = 0; j < size; q.pop(), j++) {
        			x = q.front();
        			for(k = 0; k < n; k++) {
        				if(graph[x][k] && !visit[k]) {
        					q.push(k);
        					visit[k] = true;
        				}
        			}
        		}
        	}
        	result[i] = depth;
        }

        int mindepth = INT_MAX;
        for(int ele : result) mindepth = min(mindepth, ele);

       	for(i = 0; i < n; i++) {
       		if(result[i] == mindepth) retvec.push_back(i);
       	}

       	return retvec;
    }
};