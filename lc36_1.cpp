class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {	// 性能太差.
        set<char> s_row[9];
        set<char> s_col[9];

        int i, j;
        char ch;
        for(i = 0; i < 9; i++) {	// 判断每行每列
        	for(j = 0; j < 9; j++) {
        		if(board[i][j] != '.') {
        			ch = board[i][j];
        			if(s_row[i].count(ch) == 1 || s_col[j].count(ch) == 1) return false;
        			s_row[i].insert(ch);
        			s_col[j].insert(ch);
        		}
        	}
        }

        set<char> ss;
        for(i = 0; i < 9; i += 3) {
        	for(j = 0; j < 9; j += 3) {
        		ss.clear();
        		for(int x = 0; x <3; x++) {
        			for(int j = 0; j < 3; j++) {
        				ch = board[i+x][j+y];
        				if(ch != '.') {
        					if(ss.count(ch) == 1) return false;
        					ss.insert(ch);
        				} 
        			}
        		}
        	}
        }
        return true;
    }
};