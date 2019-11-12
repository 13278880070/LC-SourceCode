#include <iostream>
#include <algorithm>

using namespace std;

struct Test
{
	int x;
	int y;
};

int main()
{
	vector<Test> vec = {{1, 5}, {2, 4}, {3, 10}, {4, 9}, {5, 20}};
	sort(vec.begin(), vec.end(), [](const Test &a, const Test &b) {
		return a.x > b.x;
	});

	for(struct Test t : vec) {
		cout<<t.y<<" ";
	}
}