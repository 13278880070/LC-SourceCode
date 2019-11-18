class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long long ret = (long long)(C-A)*(long long)(D-B) + (long long)(G-E)*(long long)(H-F);
        
        int len1 = getLen(A, C, E, G);
        int len2 = getLen(B, D, F, H);
        
        ret -= len1*len2;
        return ret;
    }
    
    // 计算相交部分
    int getLen(int A, int C, int E, int G) {
        int ret = 0;
        if(A <= E && E < C) {
            ret = min(C, G) - E;
        } else if(E <= A && A < G) {
            ret = min(C, G) - A;
        }
        return ret;
    }
};