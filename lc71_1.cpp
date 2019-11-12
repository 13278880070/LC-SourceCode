class Solution {
public:
    string simplifyPath(string path) {
    	// 使用 stack 来实现, 必要的时候需要 reverse.
        vector<string> vec;
        stack<string> stk;
        string str;
        int len = path.length();
        for(int i = 0; i < len; i++) {
        	if(path[i] == '/') {
        		if(str.length() != 0) vec.push_back(str);
        		str = "";
        		continue;
        	}
        	str += path[i];
        }
        if(str.length() != 0) vec.push_back(str);
        for(int i = 0; i < vec.size(); i++) {
        	if(vec[i] == "..") {
        		if(!stk.empty()) stk.pop();
        	} else if(vec[i] == ".") continue;
        	else {
        		stk.push(vec[i]);
        	}
        }
        str = "";
        string s;
        while (!stk.empty()) {
            s = stk.top();
            reverse(s.begin(), s.end());
        	str += s;
        	str += "/";
        	stk.pop();
        }
        if(str.length() == 0) return "/";
        reverse(str.begin(), str.end());
        return str;
    }
};