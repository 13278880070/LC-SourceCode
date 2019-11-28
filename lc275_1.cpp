class Solution {	// 已排序, H 指数
public:				// log(n) time
	int ret, len;
    int hIndex(vector<int>& citations) {
        ret = 0;
        len = citations.size();

        int l = 0, r = len - 1, mid;

        while (l < r) {
            cout<<l<<" "<<r<<endl;
        	mid = (l + r) >> 1;
        	if (citations[mid] == (len - mid) || citations[mid] == (len - mid - 1)) {
        		return citations[mid];
        	}
        	if (citations[mid] > (len - mid)) {
        		ret = max(ret, len - mid);
        		r = mid;
        	} else if(citations[mid] < (len - mid - 1)) {
        		ret = max(ret, citations[mid]);
        		l = mid + 1;
        	}
        }
        if (l == r && citations[l] > 0) ret = max(ret, 1); 
        return ret;
    }
};