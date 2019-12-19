class Solution {	// 水壶问题    x, y 的瓶子 => 得到容量为 z
public:
	// 辗转相除法求解最大公约数
	int gcd(int a, int b) {
		return a % b == 0 ? b : gcd(b, a % b);
	}

	// 更相减损术
	// int gcd(int a, int b) {
	// 	if (a == b) return a;
 //        if (a > b) return gcd(a-b, b);
 //        else return gcd(b-a, a);
	// }

    bool canMeasureWater(int x, int y, int z) {
        if (!z) return true;
        if (x + y < z) return false;
        if (!x) return z % y == 0;
        if (!y) return z % x == 0;
        return x > y ? (z % gcd(x, y) == 0) : (z % gcd(y, x) == 0);
    }

    // 变成求解二元一次方程是否有整数解的过程。
    // aX + bY = c
    // 有整数解: a 和 b 的最大公约数可以被 c 整除.
};