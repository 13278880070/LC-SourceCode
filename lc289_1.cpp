class Solution {	// live [2, 3] => live,   die [3] => live
public:				// 60.73%.
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        if(n == 0) return ;
        int m = board[0].size();

        vector<vector<int>> vec = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};

        vector<int> lvec;
        int count, a, b, i, j;

        for(i = 0; i < n; i++) {
        	for(j = 0; j < m; j++) {
        		count = 0;
        		for(vector<int> v : vec) {
        			a = i + v[0];
        			b = j + v[1];
        			if (a >= 0 && a < n && b >= 0 && b < m) count += board[a][b];
        		}

        		if(count == 3) lvec.push_back(i * m + j);
        		else if(count == 2) {
        			if(board[i][j] == 1) lvec.push_back(i * m + j);
        		}
        	}
        }

        for(i = 0; i < n; i++) {
        	for(j = 0; j < m; j++) {
        		board[i][j] = 0;
        	}
        }

        for(int ele : lvec) {
        	a = ele / m;
        	b = ele % m;

        	board[a][b] = 1;
        }

        
    }
};