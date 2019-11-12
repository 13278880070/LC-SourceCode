class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {	// beat 89.81%
        set<char> s_row[9];
        set<char> s_col[9];
        set<char> ss[9];

        int i, j, boxn;
        char ch;
        for(i = 0; i < 9; i++) {	// 判断每行每列
        	for(j = 0; j < 9; j++) {
        		if(board[i][j] != '.') {
        			boxn = (i / 3) * 3 + (j / 3);
        			ch = board[i][j];
        			if( s_row[i].count(ch) || s_col[j].count(ch) || ss[boxn].count(ch) ) return false;
        			s_row[i].insert(ch);
        			s_col[j].insert(ch);
        			ss[boxn].insert(ch);
        		}
        	}
        }
        return true;
    }
};