#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	
	reverse(vec.begin(), vec.end());
	cout<<vec[0];
 } 
