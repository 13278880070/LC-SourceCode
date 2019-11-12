class UF
{
private:
	int *pa;
	int *rank;
	int count;
public:
	UF(int N) {
		count = N;
		pa = new int[N];
		rank = new int[N];

		for(int i = 0; i < N; i++) {
			pa[i] = i;
			rank[i] = 0;
		}
	}

	~UF() {
		delete []pa;
		delete []rank;
	}

	// 是否同一颗子树.
	bool find(int a, int b) {
		return getroot(a) == getroot(b);
	}

	// 返回当前子树根节点.
	int getroot(int a) {
		while (pa[a] != a) a = pa[a];
		return a;
	}

	// 将任意两个结点所在的树合并.
	void unichild(int a, int b) {
		a = getroot(a);
		b = getroot(b);
		if(a != b) {
			if(rank[a] > rank[b]) {
				pa[b] = a;
			} else if(rank[a] < rank[b]) {
				pa[a] = b;
			} else {
				pa[b] = a;
				rank[a]++;
			}
			count--;
		}
	}
    
    int getcount() {return count;}
};

class Solution {	// '1' 代表 land, '0' 代表 water
public:				// 返回所有的 "islands"   (个人思路, 想到了之前的并查集!)
    int numIslands(vector<vector<char>>& grid) {
    	int n = grid.size();
    	if(!n) return 0;
    	int m = grid[0].size();


        UF uf = UF(m*n+1);	// 使用一个虚拟的 root, 来合并所有的'1'
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
        		if(grid[i][j] == '0') {
        			uf.unichild(i*m+j, n*m);
        		} else {
        			if(i != 0 && grid[i-1][j] == '1') uf.unichild((i-1)*m+j, i*m+j);
        			if(j != 0 && grid[i][j-1] == '1') uf.unichild(i*m+j-1, i*m+j);
        		}
        	}
        }
        
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
                cout<<uf.getroot(i*m + j)<<" ";
            }
            cout<<endl;
        }

        return uf.getcount()-1;
    }
};