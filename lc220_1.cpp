class Solution {	// 是否存在 abs(i-j) <= k 且 abs(nums[i]-nums[j]) <= t 的两个整数
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k && i - k - 1 < nums.size()) window.erase(nums[i - k - 1]);
            auto it = window.lower_bound((long long)nums[i] - t);
            // lower_bound: *it >= nums[i]-t, 即 nums[i]-*it <= t 的 *it
            if (it != window.cend() && *it - nums[i] <= t) return true;
            // 如果 *it-nums[i] <= t, 则满足 abs(*it-nums[i]) <= t, 返回 true
            window.insert(nums[i]);
        }
        return false;
    }
    // 使用有序 set 来解答, set 元素 <= k+1 个
    // 如果出现重复元素 x, y => 则 x, y 之差为 0, 将满足为 true 的条件.
};