class Solution {	// 行, 列 均有序的二维数组, 查找一个元素
public:				// 从左下角开始查找
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(!n) return false;
        int m = matrix[0].size();

        int i = n-1, j = 0;

        bool ret = false;
        while (i >= 0 && j < m) {
        	if(matrix[i][j] > target) i--;
        	else if(matrix[i][j] < target) j++;
        	else {
        		ret = true;
        		break;
        	}
        }
        return ret;
    }
};