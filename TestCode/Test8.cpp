#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <sstream>
#include <unordered_map>

using namespace std;

int main()
{
	// vector<int> vec = {1,3,2,2,2,1,1,3,1,1,2};

	// vector<int> vec = {1,3,2,2,3,1};

	vector<int> vec = {4,5,5,5,5,6,6,6};

	vector<int> nums = vec;

	    // int len = nums.size();

     //    auto midptr = nums.begin() + (len >> 1);

     //    nth_element(nums.begin(), midptr, nums.end());

     //    int midnum = *midptr;

     //    for (int j = 0; j < len; j++) cout<<nums[j]<<" ";

	int len = vec.size();

	auto midptr = vec.begin() + (len >> 1);

	nth_element(vec.begin(), midptr, vec.end(), greater<int>());

	cout<<"[grea]  mid: "<<*midptr<<"; ";

	for (int ele : vec) cout<<ele<<" ";

	cout<<endl;

	cout<<*midptr<<" "<<*(midptr+1)<<endl;

	cout<<endl;

	midptr = nums.begin() + (len >> 1);

	nth_element(nums.begin(), midptr, nums.end());

	cout<<"[less]  mid: "<<*midptr<<"; ";

	for (int ele : nums) cout<<ele<<" ";

	cout<<endl;

	cout<<*midptr<<" "<<*(midptr+1)<<endl;

	cout<<*(nums.end()-1)<<endl;
}