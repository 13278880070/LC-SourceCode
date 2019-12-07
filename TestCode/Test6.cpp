#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
	vector<int> nums = {1, 2, 3, 4};

	vector<vector<int> > Bucket(nums.size(), vector<int>());
	Bucket[0].push_back(1);

	cout<<Bucket[0][0]<<endl;
}