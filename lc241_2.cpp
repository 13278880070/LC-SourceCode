class Solution {    // 分治法, 找到 '+', '-', '*' 进行切分, 分治.
public:
    vector<int> diffWaysToCompute(string input) {
        int len = input.length();
        vector<int> retvec;
        char ch;
        for(int i = 0; i < len; i++) {
            ch = input[i];
            if(ch == '*' || ch == '+' || ch == '-') {
                // 以 ch 为切分点, 分治.
                vector<int> vec1 = diffWaysToCompute(input.substr(0, i));
                vector<int> vec2 = diffWaysToCompute(input.substr(i+1));
                
                for(int ele1 : vec1) {
                    for (int ele2 : vec2) {
                        if(ch == '*') retvec.push_back(ele1 * ele2);
                        else if(ch == '+') retvec.push_back(ele1 + ele2);
                        else retvec.push_back(ele1 - ele2);
                    }
                }
            }
        }
        if(retvec.size() == 0) retvec.push_back(stoi(input));
        return retvec;
    }
};