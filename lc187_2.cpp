class Solution {	// 将长度为 10 的一个序列, 通过相关运算转化为一个 int 型的数.
public:				// 使用 hash 来记录每个序列(即对应 int 型) 出现的次数.
	// 16 进制: 0x41, 0x43, 0x47, 0x54
	// 最后一个分别为 1, 3, 7, 4.
	// 使用 3 bit 即可存储这 4 个数.
	// 因此, s[i] & 7, 得到对应的数.
	// 并以此存储到 t 中.
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        vector<string> vec;
        unordered_map<int, int> map;
        if(len < 10) return vec;
        int i = 0, t = 0;
        // 1. 将前 9 个数存到 t 中, 已使用 27 bit
        while (i < 9) {
        	t = (t << 3) | (s[i++] & 7);
        }

        for(; i < len; i++) {
        	t &= 0x7FFFFFF;			// 保存前 9 个数.
        	t = (t << 3) | (s[i] & 7);	// 添加当前数.
        	if(map[t]++ == 1) vec.push_back(s.substr(i-9, 10));
        	// ++ 操作在 运算之后.
        }
        return vec;
    }
};