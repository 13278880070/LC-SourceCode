class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	int x, y;
    	int n = board.size();
    	if(n == 0) return false;
    	int m = board[0].size();
    	for(x = 0; x < n; x++) {
    		for(y = 0; y < m; y++) {
    			if(board[x][y] == word[0]) {
    				if(findword(board, word, x, y, 0)) return true;
    			}
    		}
    	}
    	return false;
    }
    
    bool findword(vector<vector<char>>& board, string word, int x, int y, int index) {
        if(board[x][y] == '*' || board[x][y] ！= word[index]) return false;
        if(index == word.length()-1) return true;
        char ch = board[x][y];
        board[x][y] = '*';
        if(x < board.size()-1 && findword(board, word, x+1, y, index+1)) return true;
        if(y < board[0].size()-1 && findword(board, word, x, y+1, index+1)) return true;
        if(x > 0 && findword(board, word, x-1, y, index+1)) return true;
        if(y > 0 && findword(board, word, x, y-1, index+1)) return true;
        board[x][y] = ch;
        return false;
    }
};