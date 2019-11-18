#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

struct cityNode{
	int id;
	int g;	// 已经花费的值
	int f;	// A* : f = g + Distance.   贪婪最佳优先: f = Distance.
	int depth;
	cityNode *parent;		// 指向当前结点父结点的指针.
	cityNode(int n1, int n2, int n3, int n4) : id(n1), g(n2), f(n3), depth(n4), parent(NULL){}
};

    int rangeBitwiseAnd(int m, int n) {
        if(m == 0) return 0;
        if(m == n) return n;
        int len1 = (int)log2(m) + 1;
        int len2 = (int)log2(n) + 1;
        if(len1 < len2) return 0;

        int sum = 0;
        for(int i = len2; i != 0; i--) {
            int x = pow(2, i-1);
            sum = sum << 1;
            int a = m / x;
            int b = n / x;
            if((a == b) && (a % 2)) {
                sum |= 1;
                cout<<"run, x "<<x<<endl;
            }
            // m &= x-1;
            // n &= x-1;
        }

        return sum;
    }
int main()
{
    int x;
    cin>>x;
    cout<<x<<endl<<x*(int)log2(x)<<endl;
}