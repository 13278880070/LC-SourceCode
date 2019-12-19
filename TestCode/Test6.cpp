#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

struct ItemNew
{
    int time;
    int userid;
    int newsid;
};

bool compare(const ItemNew &a, const ItemNew &b) {
    return a.time < b.time;
};

int main()
{
	auto compare = [](vector<int> a, vector<int> b) {
		return a[0] + a[1] > b[0] + b[1];
	};
	priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> q(compare);

	q.emplace(vector<int>{3, 3});
	q.emplace(vector<int>{2, 3});
}