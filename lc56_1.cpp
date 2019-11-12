class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> retvec;
        int size = intervals.size();
        if(size <= 1) return intervals;
        sort(intervals.begin(), intervals.end());	// 按照第一个元素排序
        int l = intervals[0][0], r;
        for(int i = 1; i < size; i++) {
            r = intervals[i-1][1];
        	while (r >= intervals[i][0] && i < size) {
                r = max(r, intervals[i][1]);	// [[1,9][2,5]]... 更新 r
                i++;
                if(i == size) {		// 是否到达最后一个元素
                    retvec.push_back({l, r});
                    return retvec;
                }
            }
        	retvec.push_back({l, r});
        	l = intervals[i][0];
        }
        retvec.push_back({l, intervals[size-1][1]});
        return retvec;
    }
};