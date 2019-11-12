class Solution {	// IP 地址划分
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> retvec;
        getIP(retvec, s, 0, 0, "" ,s.length());
        return retvec;
    }

    void getIP(vector<string>& retvec, string s, int index, int count, string str, int len) {
    	if(count == 3) {
    		cout<<str<<" ";
    		if(index < len) {
    			cout<<s.substr(index, len)<<endl;
    			if(stoi(s.substr(index, len)) <= 255) {	// 最后一节.
    				str += s.substr(index, len);
    				retvec.push_back(str);
    			}
    		}
    		return ;
    	}
    	if(index < len) getIP(retvec, s, index+1, count+1, str + s[index] + '.', len);
    	if(index+2 < len) getIP(retvec, s, index+2, count+1, str + s.substr(index, index+2) + '.', len);
    	if(index+3 < len) {
    		if(stoi(s.substr(index, index+3)) <= 255) getIP(retvec, s, index+3, count+1, str + s.substr(index, index+3) + '.', len);
    	}
    }
};