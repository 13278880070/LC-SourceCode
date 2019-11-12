class Solution {
public:
	// 使用位来存储每个字符 'A', 'C', 'G', 'T'.
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.length();
        vector<string> retvec;
        if(len <= 9) return retvec;

        // 00, 01, 10, 11. 每个字符使用两位存储
        unordered_map<char, int> map = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_map<int, int> countmap;	// 记录每个 sum 出现次数.

       	int i = 0, sum = 0;
       	while (i < 9) sum = (sum << 2) | map[s[i++]];

       	while (i < len) {
       		sum &= 0x3FFFF;
       		sum = (sum << 2) | map[s[i++]];
       		if(countmap[sum]++ == 1) retvec.push_back(s.substr(i-10, 10));
       	}
       	return retvec;
    }
};