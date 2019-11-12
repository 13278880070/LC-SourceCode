class Solution {	// 版本比较
public:				// 单个字符进行处理.
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        int sum1 = 0, sum2 = 0, index1 = 0, index2 = 0;
        while(index1 < len1 || index2 < len2) {
        	while (index1 < len1 && version1[index1] != '.') {	// 两个条件来确定 '.' 分割开的所有版本号.
        		sum1 = sum1*10 + version1[index1++] - '0';
        	}

        	while (index2 < len2 && version2[index2] != '.') {
        		sum2 = sum2*10 + version2[index2++] - '0';
        	}

        	if(sum1 > sum2) return 1;
        	if(sum1 < sum2) return -1;

        	sum1 = 0;
        	sum2 = 0;
            index1++;
            index2++;
        }
        return 0;
    }
};