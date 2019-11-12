#include <iostream>
#include <vector>

using namespace std;	// 求解: 一组整数中, 一个数出现 p 次, 其他数出现 k 次, 找到这个单独的数.

// k = 3, p = 1.
void count1() {	
	vector<int> vec = {2,2,2,3,4,3,3};
	// x1 => 记录 num 出现一次.
	// x2 => 记录 num 出现两次.
	// k = 3 => mask = ~(x2 & x1) => "x2x1". num 达到 3 次清零.
	int x2 = 0, x1 = 0, mask;

	for(int num : vec) {
		x2 ^= x1 & num;
		x1 ^= num;
		mask = ~(x1 & x2);
		x1 &= mask;
		x2 &= mask;
	}
	cout<<x1<<endl;
}

// k = 4, p = 2
void count2() {
	vector<int> vec = {1,1,1,1,3,4,4,4,3,4};
	// k = 4. 最大数位 "100". 需要三位 x3,x2,x1 来记录.
	int x3 = 0, x2 = 0, x1 = 0, mask;
	for(int num : vec) {
		x3 ^= x2 & x1 & num;
		x2 ^= x1 & num;
		x1 ^= num;
		mask = ~(x3 & ~x2 & ~x1);	// 记录达到 4 次, mask 为零.
		x3 &= mask;
		x2 &= mask;
		x1 &= mask;
	}
	// p = 2. => "010" => 输出 x2 即可.;
	cout<<x2<<endl;
}

int main()
{
	count1();
	count2();
	return 0;
}