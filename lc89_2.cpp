class Solution {
public:
    vector<int> grayCode(int n) {   // 定义解题, 第 x 位: gray = x ^ (x>>1)
        vector<int> res;
        int num = 0;
        int a = 1<<n;
        for(int i = 0; i < a; i++) {
            num = i ^ (i>>1);
            res.push_back(num);
        }
        
        return res;
    }
};