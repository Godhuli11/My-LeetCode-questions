class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        
        if(k == n) {
            return "0";
        }
        
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() > num[i] - '0' && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i] - '0');
        }
        
        // If there are still digits to remove
        while(k > 0) {
            st.pop();
            k--;
        }
        
        string res = "";
        
        while(!st.empty()) {
            res.push_back(st.top() + '0');
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        // Remove leading zeros
        int cnt = 0;
        for(int i = 0; i < res.size(); i++) {
            if(res[i] == '0') {
                cnt++;
            } else {
                break;
            }
        }
        
        res = res.substr(cnt);
        
        return res.empty() ? "0" : res;
    }
};
