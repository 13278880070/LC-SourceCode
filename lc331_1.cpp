class Solution {	// 根据前序遍历, 判断是否为二叉树.
public:				// 对于当前结点, 要么为单独结点, 要么有两个孩子结点.
					// Error Answer... can't ac...
	string preorder;
    bool isValidSerialization(string preorder) {
        int len = preorder.size();
		this->preorder = preorder;
		int x = 0;
		while (x < len && preorder[x] != ',') x++;
		if (x == len) return preorder[0] == '#';
		if (preorder[0] == '#') return false;
		return isValidNode(0, len-1);
    }
	
	bool isValidNode(int l, int r) {
		if (l > r) return false;
		
		int x = l;
		while (x <= r && preorder[x] != ',') {
			x++;
		}
		if (x > r) return true;
        
        // if (preorder[l] == '#') return false;
		
		x++;
		int y = x;
		for (; y <= r; y++) {
			if (preorder[y] == ',') {
				if (isValidNode(x, y-1) && isValidNode(y+1, r)) return true;
			}
		}
		
		return false;
	}
};