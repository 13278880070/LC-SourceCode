class Solution {	// 计算除法.
public:				// 哈希表!.
    string fractionToDecimal(int num, int denom) {
        // 处理正负, 整数部分
        if(num == 0) return "0";
        string res;

        long numerator = (long)num;
        long denominator = (long)denom;
        if((numerator < 0) ^ (denominator < 0)) res += '-';
        numerator = abs(numerator);
        denominator = abs(denominator);

        res += to_string(numerator / denominator);
        if((numerator %= denominator) == 0) return res;

        // 处理小数部分.
        res += '.';
        unordered_map<int, int> map;
        // map 来记录前面出现过的 分子.
        // <num, index>
        while (numerator != 0) {
        	if(map.find(numerator) == map.end()) {
        		map[numerator] = res.length();
        		numerator *= 10;
	        	res += to_string(numerator / denominator);
	        	numerator %= denominator;
        	} else {	// 前面出现过相同的"分子"
        		res.insert(res.begin()+map[numerator], '(');
        		res += ')';
        		break;
        	}
        }
        return res;
    }
};