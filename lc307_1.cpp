class NumArray {
private:
	vector<int> nums;
	vector<int> BIT;
	int N;

public:
    NumArray(vector<int>& nums) {
    	this->nums = nums;
    	N = nums.size();
        BIT = vector<int>(N+1, 0);
        // 初始化为 0, 使用 update 方法来对 BIT 进行初始化

        int i, k;
        for (i = 0; i < N; i++) {
        	k = i + 1;

        	while (k <= N) {
        		BIT[k] += nums[i];
        		k = k + (k & -k);
        	}
        }

        for(i = 1; i <= N; i++) cout<<BIT[i]<<" ";
    }
    
    // 更新 nums[i] = val
    void update(int i, int val) {
        int add = val - nums[i];
        nums[i] = val;

        int k = i+1;
        while (k <= N) {	// 根据索引 k, 更新每个 BIT
        	BIT[k] += add;
        	k = k + (k & -k);
        	// k & -k  =>  取 0b(k) 的最后一个 1
        	// 往后索引的规则是: 每次都加上最后一个 1
        }
    }
    
    int sumRange(int i, int j) {
    	int a = 0, b = 0;
        int k = i;
        while (k > 0) {
        	a += BIT[k];
        	k = k - (k & -k);
        }
        k = j + 1;
        while (k > 0) {
        	b += BIT[k];
        	k = k - (k & -k);
        }

        return b - a;
    }
};