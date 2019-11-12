class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int a, b;

        for(string str : tokens) {
        	if(str.size() == 1 && !isdigit(str[0])) {
        		a = stk.top();
        		stk.pop();
        		b = stk.top();
        		stk.pop();
        		if(str == "+") stk.push(a + b);
        		else if(str == "/") stk.push(b / a);
        		else if(str == "*") stk.push(a * b);
        		else if(str == "-") stk.push(b - a);
        	} else stk.push(stoi(str));
        }

        return stk.top();
    }
};