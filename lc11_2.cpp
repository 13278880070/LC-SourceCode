class Solution {    // AC
public:
    int maxArea(vector<int>& height) {  // vector<int>& 用于传引用
        int len = height.size(), ret = 0;
        int l = 0, r = len - 1;
        while (l < r) {
            int h = min(height[l], height[r]);
            ret = max(ret, (r - l)*h);
            
            while (l < r && height[l] <= h) l++;
            while (r > l && height[r] <= h) r--;
        }
        return ret;
    }
};