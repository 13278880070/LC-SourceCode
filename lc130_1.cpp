class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return ;
        int m = board[0].size();
        if(n <= 2 || m <= 2) return ;

        for(int j = 0; j < m; j++) {
        	if(board[0][j] == 'O') {
        		board[0][j] = '*';
        		solveit(0, j, board);
        	}
        	if(board[n-1][j] == 'O') {
        		board[n-1][j] = '*';
        		solveit(n-1, j, board);
        	}
        }

        for(int i = 1; i < n-1; i++) {
        	if(board[i][0] == 'O') {
        		board[i][0] = '*';
        		solveit(i, 0, board);
        	}
        	if(board[i][m-1] == 'O') {
        		board[i][m-1] = '*';
        		solveit(i, m-1, board);
        	}
        }
        
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
                if(board[i][j] == '*') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }

    void solveit(int i, int j, vector<vector<char>>& board) {
    	if(i > 0 && board[i-1][j] == 'O') {
    		board[i-1][j] = '*';
    		solveit(i-1, j, board);
    	}
    	if(i < board.size()-1 && board[i+1][j] == 'O') {
    		board[i+1][j] = '*';
    		solveit(i+1, j, board);
    	}
    	if(j > 0 && board[i][j-1] == 'O') {
    		board[i][j-1] = '*';
    		solveit(i, j-1, board);
    	}
    	if(j < board[0].size()-1 && board[i][j+1] == 'O') {
    		board[i][j+1] = '*';
    		solveit(i, j+1, board);
    	}
    }
};