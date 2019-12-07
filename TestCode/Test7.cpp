#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<vector<int>> retvec;

void calculate(vector<int> vec) 
{
	vec.push_back(1);
	vec.push_back(2);
	retvec.push_back(vec);
}

int main()
{
	vector<int> vec;
	calculate(vec);
	calculate(vec);

	for (vector<int> vec : retvec) {
		for (int ele : vec) cout<<ele<<" ";
		cout<<endl;
	}
}