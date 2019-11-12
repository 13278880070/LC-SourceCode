class UF {
private:
	int *parent;	// 父指针数组.
	int *rank;		// rank. (这里就是每个子树的高度.)
	int count;

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

		count = 0;
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
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0) return ;
        int m = board[0].size();

        UF *uf = new UF(n*m + 1);	// 最后一个结点为虚拟结点, 用于连接所有 边界'O' 以及与 边界'O' 连通的结点.

        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
        		if(board[i][j] == 'O') {
        			if(i == 0 || j == 0 || i == n-1 || j == m-1) {	// 边界 'O'
        				uf->unichild(i*m + j, m*n);
        			} else {	// 非边界 'O'
        				if(board[i-1][j] == 'O') {
        					uf->unichild((i-1)*m + j, i*m + j);
        				}
        				if(board[i+1][j] == 'O') {
        					uf->unichild((i+1)*m + j, i*m + j);
        				}
        				if(board[i][j-1] == 'O') {
        					uf->unichild(i*m + j-1, i*m + j);
        				}
        				if(board[i][j+1] == 'O') {
        					uf->unichild(i*m + j+1, i*m + j);
        				}
        			}
        		}
        	}
        }

        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
        		if(board[i][j] == 'O' && uf->diff(i*m + j, m*n)) {
        			board[i][j] = 'X';
        		}
        	}
        }
    }
};