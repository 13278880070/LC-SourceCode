class Solution {	// 碰到 负数, 替换 nmax, nmin
public:
    int maxProduct(vector<int>& nums) {
        int nmin = INT_MAX/100, nmax = INT_MIN/100, ret = nmax;
        for(int num : nums) {
        	if(num < 0) {
        		swap(nmin, nmax);
        	}
        	nmax = max(num, nmax*num);
        	nmin = min(num, nmin*num);
        	ret = max(ret, nmax);
        }
        return ret;
    }
};