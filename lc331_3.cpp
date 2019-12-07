class Solution {
public:
	// 使用 stringstream.
    bool isValidSerialization(string preorder) {
        if (!preorder.size()) return false;
        
        stringstream ss(preorder);
        int nodeneed = 1;
        string str;
        while (getline(ss, str, ',')) {
            nodeneed--;
            if (nodeneed < 0) return false;
			// nodeneed < 0, 表示空结点出现孩子结点的情况.
			
            if (str[0] != '#') nodeneed += 2;
        }
        
        return nodeneed == 0;
    }
};