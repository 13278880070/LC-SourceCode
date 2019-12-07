class Solution {	// 根据前序遍历, 判断是否满足二叉树.
public:
    bool isValidSerialization(string preorder) {
        int nodeneed = 1, len = preorder.size();
        if (!len) return false;
        preorder += ',';
		
		for(int i = 0; i < len+1; i++) {
			if (preorder[i] != ',') continue;
			
			nodeneed--;    // 已得到一个结点.
			if (nodeneed < 0) return false;
			
			if(preorder[i-1] != '#') nodeneed += 2;
            // 一个非空结点, 对应有两个孩子结点.
		}
		
		return nodeneed == 0;
    }
};