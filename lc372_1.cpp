class Solution {	// 求解 a^b 对 1337 取模
private:
	int k = 1337;
public:
	int doPow(int a, int b) { // a ^ b 对 k 取模, 这里 0 <= b < 10
		a %= k;
		int ret = 1;
		for (int i = 0; i < b; i++) {
			ret = (ret * a) % k;
		}
		return ret;
	}

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int b0 = b.back();
        b.pop_back();
        return doPow(superPow(a, b), 10) * doPow(a, b0);
    }
};