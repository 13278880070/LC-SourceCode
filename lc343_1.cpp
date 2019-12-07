class Solution {
public:
    int integerBreak(int n) {
        int ret = 1;

       	while (n > 4) {
       		n -= 3;
       		ret *= 3;
       	}
       	if (n < 4) ret *= (n-1);
       	else ret *= 4;
       	return ret;
    }
};