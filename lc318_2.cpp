class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len = words.size();
        
        // 位运算存放所有 word
        vector<int> letter(len, 0);

        sort(words.begin(), words.end(), [](const string &str1, const string &str2){
            return str1.length() < str2.length();
        });

        for(int i = 0; i < len; i++) {
            for (char ch : words[i]) {
                letter[i] |= 1 << (ch - 'a');
            }
        }

        // 错误做法, 可能前面更小的 str1 可以与后面更大的 str2 匹配..
        int ret = 0;
        for(int i = len - 2; i >= 0; i--) {
            for(int j = len - 1; j > i; j--) {
                if (!(letter[i] & letter[j])) {
                    return (int)(words[i].length() * words[j].length());
                }
            }
        }

        return 0;
    }
};