class Solution {	// 太慢..
public:
    int numTrees(int n) {
        return getnum(1, n);
    }
    
    int getnum(int l, int r) {
        if(l == r) return 1;
        if(l > r) return 0;
        if(r - l == 1) return 2;
        if(r - l == 2) return 5;
        int ret = 0;
        for(int i = l; i <= r; i++) {
            ret += getnum(l, i-1);
            ret += getnum(i+1, r);
        }
        return ret;
    }
};