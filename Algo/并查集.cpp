#include <iostream>

using namespace std;

class UF {
private:
	int *parent;	// 父指针数组.
	int *rank;		// rank. (这里就是每个子树的高度.)
	int count;		// 子树数量.

	int find(int p) {		// 返回该节点所在树的根节点.
		while (p != parent[p]) {
			p = parent[p];
		}
		return p;
	}

public:
	UF(int N) {
		parent = new int[N];
		rank = new int[N];

		// 初始每个结点都是一个子树.
		for(int i = 0; i < N; i++) {
			parent[i] = i;
			rank[i] = 0;
		}

		count = N;
	}
	~UF() {
		delete [] parent;
		delete [] rank;
	}

	void uni(int p, int q) {	// 合并两个子树(根节点).
		if(rank[p] > rank[q]) {
			parent[q] = p;
		} else if(rank[p] < rank[q]) {
			parent[p] = q;
		} else {
			parent[p] = q;
			rank[q]++;
		}
		count--;
	}

	void unichild(int p, int q) {	// 合并任意两个结点所在的树.
		if(diff(p, q)) {
			uni(find(p), find(q));
		}
	}

	bool diff(int p, int q) {	// 是否在同一颗树中.
		int Pp = find(p);
		int Pq = find(q);
		if(Pp == Pq) return false;
		return true;
	}

	int getcount() {return count;}
};

int main()
{
	UF *uf = new UF(10);
	uf->unichild(0, 1);
	uf->unichild(0, 2);
	uf->unichild(0, 3);
	uf->unichild(2, 4);
	uf->unichild(4, 9);

	cout<<uf->getcount()<<endl;

	cout<<uf->diff(4, 9)<<endl;
}