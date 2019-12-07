class Solution {	// 状态转移, DP
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if(!len) return 0;

        vector<int> Buy(len);
        vector<int> Sell(len);
        vector<int> Cold(len);
        // i, 分别表示第 i 次操作为 买, 卖, 冷冻 时的最大获利

        Buy[0] = -prices[0];
        Sell[0] = 0;
        Cold[0] = 0;

        // 根据转移图, Buy[i] 可以由 Buy[i-1] 和 Cold[i-1] 转移.
        // Cold[i] 可以由 Cold[i-1] 和 Sell[i-1] 转移.
        for(int i = 1; i < len; i++) {
        	Buy[i] = max(Buy[i-1], Cold[i-1] - prices[i]);
        	Cold[i] = max(Cold[i-1], Sell[i-1]);
        	Sell[i] = Buy[i-1] + prices[i];
        }

        return max(Buy[len-1], max(Cold[len-1], Sell[i-1]));
    }
};