class Solution {	// gas, cost. 加气站.
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        unordered_set<int> reset;
        int ret = 0, sum = 0;
        reset.insert(0);
        int len = gas.size();
        int i = 0;
        while (i != (len + ret -1) % len) {	// 循环.
        	sum += (cost[i] - gas[i]);
        	if(sum > 0) {
        		ret = (i + 1) % len;
                if(reset.count(ret) != 0) return -1;
                reset.insert(ret);
        		sum = 0;
        	}
            i = (i + 1) % len;
        }
        sum += (cost[i] - gas[i]);
        return sum <= 0? ret : -1;
    }
};