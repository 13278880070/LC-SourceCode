class Solution {
	// 134_1.cpp 做法多余.
	// 直接遍历一次即可.
	// 两个 idea:
	// 		1. 如果 B 是 A 无法到达的第一个点, 则 A-B 的中间结点均无法到达 B
	//		2. 如果 sum(gas) >= sum(cost), 则必有一个解存在.
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ret = 0, len = gas.size();
        int sum = 0, leave = 0;
        for(int i = 0; i < len; i++) {
        	sum += (gas[i] - cost[i]);
        	leave += (gas[i] - cost[i]);
        	if(sum < 0) {
        		ret = i + 1;
        		sum = 0;
        	}
        }
        // leave 记录总的 gas, cost.
        return leave >= 0? ret : -1;
    }
};