class Solution {	//
public:
    vector<string> generateParenthesis(int n) {		// 回溯
        vector<string> retvec;
        genarateit("", retvec, 0, 0, n);
        return retvec;
    }

    void genarateit(string str, vector<string> &vec, int lparen, int rparen, int n) {
    	if(lparen == n && rparen == n) {
            vec.push_back(str);		// 此处直接 push_back 啊 !!!!
            return;
        }
        if(rparen > lparen || lparen > n || rparen > n) return;     
        // ')' 多于 '(', 直接 return.
    	genarateit(str+'(', vec, lparen + 1, rparen, n);
    	genarateit(str+')', vec, lparen, rparen + 1, n);
    }
};