class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> retvec;
        vector<int> vec;
        getcombie(retvec, vec, n, k, 0, 0);
        return retvec;
    }

    void getcombie(vector<vector<int>>& retvec, vector<int>& vec, int n, int k, int count, int start) {
    	if(count == k) {
    		retvec.push_back(vec);
    		return ;
    	}
    	for(int i = start+1; i <= n; i++) {		// 后面每次递归都选取比当前值大的数.
    		vec.push_back(i);
    		getcombie(retvec, vec, n, k, count+1, i);
    		vec.pop_back();
    	}
    }
};