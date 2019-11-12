#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> nums = {1,2,3,4,5,6,7,8,9,0};
	sort(nums.begin(), nums.end(), [](const int &n1, const int &n2) {
		if(!n1) return 0;
		if(!n2) return 1;
    	// n1n2, n2n1 比较.
    	int len1 = (int)log10(n1) + 1;
    	int len2 = (int)log10(n2) + 1;

    	long num1 = n1*pow(10, len2) + n2;
    	long num2 = n2*pow(10, len1) + n1;

    	return num1 > num2 ? 1 : 0;
    });
	
	for(int ele : nums) cout<<ele<<" ";
	return 0;
}