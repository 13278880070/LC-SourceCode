class Solution {	// 执行效率低下...
public:
    vector<string> generateParenthesis(int n) {		// 回溯
        vector<string> retvec;
        genarateit("", retvec, 0, 0, n);
        return retvec;
    }

    void genarateit(string str, vector<string> &vec, int lparen, int rparen, int n) {
    	if(lparen + rparen == 2*n) {
    		if(isvalid(str)) vec.push_back(str);
    		return;
    	}
    	if(lparen < n) genarateit(str+'(', vec, lparen + 1, rparen, n);
    	if(rparen < n) genarateit(str+')', vec, lparen, rparen + 1, n);
    }

    bool isvalid(string str) {
    	int len = str.length(), i = 0;
    	stack<char> stk;
    	while (i != len) {
    		if(str[i] == '(') stk.push('(');
    		else {
                if(stk.empty()) return false;
                stk.pop();
            }
    		i++;
    	}
    	return (i == len && stk.empty());
    }
};