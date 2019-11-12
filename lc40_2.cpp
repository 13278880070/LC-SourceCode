class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) 
    {
        vector<vector<int>> res;
        sort(num.begin(),num.end());
        vector<int> local;
        findCombination(res, 0, target, local, num);
        return res;
    }
    void findCombination(vector<vector<int>>& res, const int order, const int remain, vector<int>& local, const vector<int>& num)
    {
        if(remain==0)
        {
            res.push_back(local);
            return;
        }
        else
        {
            for(int i = order;i<num.size();i++)	// 每次循环都是选取下一个结点
            {
                if(num[i]>remain) return;
                if(i&&num[i]==num[i-1]&&i>order) continue; // check duplicate combination
                local.push_back(num[i]),
                findCombination(res,i+1,remain-num[i],local,num); // recursive componenet
                local.pop_back();
            }
        }
    }
};