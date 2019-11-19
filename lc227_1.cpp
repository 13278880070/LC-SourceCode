class Solution {	// 计算 ' ', digit, op 组成的字符串的值
public:				// 7.56%....
    int calculate(string s) {
        int len = s.length();

        stack<int> dstk;
        stack<char> cstk;

        int i, num, n;
        char ch;
        for(i = 0; i < len; i++) {
        	if(s[i] == ' ') continue;
        	if(isdigit(s[i])) {
        		num = 0;
	        	while (i < len && isdigit(s[i])) {
                    n = s[i] - '0';
	        		num = num*10 + n;
                    i++;
	        	}
                i--;
	        	dstk.push(num);
	        	if(!cstk.empty()) {
	        		ch = cstk.top();
	        		if(ch == '/' || ch == '*') {
	        			int a = dstk.top();
		        		dstk.pop();
		        		int b = dstk.top();
		        		dstk.pop();

		        		dstk.push(cal(b, a, cstk.top()));
		        		cstk.pop();
	        		}
	        	}
        	} else {
        		cstk.push(s[i]);
        	}
        }
        // 一个一个地算
        int ret = 0;
        while (!cstk.empty()) {
        	int a = dstk.top();
		    dstk.pop();

		    ret = cal(ret, a, cstk.top());
            cout<<cstk.top()<<endl;
		    cstk.pop();
        }

        return ret+dstk.top();
    }

    int cal(int a, int b, char ch) {
    	switch(ch) {
    		case '+':
    			return a+b;
    		case '-':
    			return a-b;
    		case '*':
    			return a*b;
    		case '/':
    			return a/b;
    	}
        return 0;
    }
};