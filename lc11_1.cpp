class Solution {	// AC
public:
    int maxArea(vector<int>& height) {	// vector<int>& 用于传引用
        int len = height.size(), ret = 0;
        int l = 0, r = len - 1;
        while (l < r) {
        	ret = max(ret, (r - l)*min(height[l], height[r]));
        	if(height[l] > height[r]) {
        		int x = r - 1;
        		while (x > 0 && (height[x] <= height[r])) x--;
        		r = x;
        	} else {
        		int x = l + 1;
        		while (x < r && (height[x] <= height[l])) x++;
        		l = x;
        	}
        }
        return ret;
    }
};