class Solution {
public:// 以 "JFK" 开始.
    vector<string> findItinerary(vector<vector<string>>& tickets) {
		// 按照目的地排序
        sort(tickets.begin(), tickets.end(), [](const vector<string> &vec1, const vector<string> &vec2){
			return vec1[1] < vec2[1];
		});
		
		unordered_map<string, vector<string>> map;
		
		for(vector<string> vec : tickets) {
			map[vec[0]].push_back(vec[1]);
		}
		
		vector<string> retvec;
		string str;
		stack<string> stk;
		stk.push("JFK");
		while (!stk.empty()) {
			str = stk.top();
			if (map[str].size() == 0) {
				retvec.push_back(str);
				stk.pop();
			} else {
				stk.push(map[str][0]);
				map[str].erase(map[str].begin());
			}
		}
		
		reverse(retvec.begin(), retvec.end());
        return retvec;
		
    }
};