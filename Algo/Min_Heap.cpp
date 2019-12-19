#include <iostream>
#include <vector>

using namespace std;

// MinHeap:
// 1. 完全二叉树
// 2. node->val >= node->parent()->val
class MinHeap
{
private:
	int* array;
	int size;
	int capacity;

public:
	MinHeap(int capa) {
		this->capacity = capa;
		this->size = 0;
		array = new int[capa];
	}

	// complete binary tree's property
	int left(int i) {return 2*i+1;}
	int right(int i) {return 2*i+2;}
	int parent(int i) {return (i-1)/2;}

	// delete, insert, ...
	void insert(int val) {
		if (size == capacity) {
			cout<<"Memory overflow!"<<endl;
			return ;
		}
		array[size++] = val;
		int i = size-1;
		while (i != 0 && array[i] < array[parent(i)]) {
			swap(array[i], array[parent(i)]);
			i = parent(i);
		}
	}

	void decreaseToVal(int i, int val) {
		array[i] = val;
		if (i <= 0 && i >= size) return ;
		while (i != 0 && array[i] < array[parent(i)]) {
			swap(array[i], array[parent(i)]);
			i = parent(i);
		}
	}

	// 删除任意一个数组下标值
	int deleteIndex(int i) {
		if (i >= size) return INT_MAX;
		int ret = array[i];
		decreaseToVal(i, INT_MIN);
		deleteMin();
		return ret;
	}

	int deleteMin() {
		if (size <= 0) {
			return INT_MAX;
		}
		int ret = array[0];
		array[0] = array[size-1];
		size--;
		MinHeapiFy(0);

		return ret;
	}

	// 递归向下, 直到满足 MinHeap 条件
	void MinHeapiFy(int i) {
		int l = left(i);
		int r = right(i);
		int smallest = i;
		if (l < size && array[l] < array[smallest]) {
			smallest = l;
		}
		if (r < size && array[r] < array[smallest]) {
			smallest = r;
		}
		if (smallest != i) {
			swap(array[smallest], array[i]);
			MinHeapiFy(smallest);
		}
	}

	bool empty() {
		return size == 0;
	}
};

int main()
{
	MinHeap* heap = new MinHeap(20);
	vector<int> vec = {1, 5, 7, 2, 6, 3, 9, 0, 4};
	for (int ele : vec) {
		heap->insert(ele);
	}
	while (!heap->empty()) {
		cout<<heap->deleteMin()<<" ";
	}    
}