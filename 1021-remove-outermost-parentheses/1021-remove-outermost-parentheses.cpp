class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char> st;
        
        string ans = "";
        
        for(char val : s){
          if(val == '('){
              if(!st.empty()){
                  ans += val;
              }
              st.push(val);
          }else{
              st.pop();
              if(!st.empty()){
                  ans += val;
              }else{
                  continue;
              }
          }     
        }
        
        return ans;
    }
};