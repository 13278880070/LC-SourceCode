#include <iostream>

using namespace std;

// 返回 x 的最后个为 1 的位.		11010 => 00010
int getlast_1(int x) {
	return (x & -x);
}

int getlast_2(int x) {
	return (x & (x-1)) ^ x;
}

int main()
{
	
}