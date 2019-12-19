class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	int len = primes.size();
    	if(!len) return 0;

        vector<int> ugly(n);
        vector<int> count(len, 0);

        ugly[0] = 1;
        for(int i = 1; i < n; i++) {
        	ugly[i] = INT_MAX;
            // 找出下一个最下的 UglyNumber.
        	for(int j = 0; j < len; j++) {
        		// 将最后更新 count[] 的操作延迟到 -下一次计算 之前-.
        		if (ugly[count[j]] * primes[j] == ugly[i-1]) {
        			count[j]++;
        		}

        		ugly[i] = min(ugly[i], ugly[count[j]] * primes[j]);
        	}
        }

        return ugly[n-1];
    }
};