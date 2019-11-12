class Solution {	// 版本比较.
public:	
    int compareVersion(string version1, string version2) {
    	int index1 = 0, index2 = 0, num1, num2;
    	bool flag1 = false, flag2 = false;	// 记录是否第一次未找到 '.'
        while (1) {
        	int in1, in2;
        	in1 = version1.find('.', index1);
        	in2 = version2.find('.', index2);

        	if(in1 == string::npos && flag1 && in2 == string::npos && flag2) return 0;

        	if(in1 == string::npos) {
        		if(!flag1) {
        			num1 = stoi(version1.substr(index1, version1.length()-index1));
        			flag1 = true;
        		} else num1 = 0;
        	} else {
        		num1 = stoi(version1.substr(index1, in1-index1));
        		index1 = in1 + 1;
        	}

        	if(in2 == string::npos) {
        		if(!flag2) {
        			num2 = stoi(version2.substr(index2, version2.length()-index2));
        			flag2 = true;
        		} else num2 = 0;
        	} else {
        		num2 = stoi(version2.substr(index2, in2-index2));
        		index2 = in2 + 1;
        	}

        	if(num1 > num2) return 1;
        	else if(num2 > num1) return -1;
        }
    }
};