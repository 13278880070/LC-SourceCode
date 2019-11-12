class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        string retstr;
        string str;
        vector<string> vec;
        for(int i = 0; i < len; i++) {
        	if(path[i] == '/') {
        		if(str.length() != 0) {
        			if(str == "..") {
        				if(vec.size() > 0) vec.pop_back();
        			} else if(str != ".") vec.push_back(str);
        		}
        		str = "";
        		continue;
        	} else str += path[i];
        }
        if(str.length() != 0) {
        	if(str == "..") {
        		if(vec.size() > 0) vec.pop_back();
        	} else if(str != ".") vec.push_back(str);
        }
        for(int i = 0; i < vec.size(); i++) {
        	retstr += "/";
        	retstr += vec[i];
        }
        if(retstr.length() == 0) return "/";
        return retstr;
    }
};