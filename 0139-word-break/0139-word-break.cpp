// class Solution {
// public:
//     unordered_set<string> st;
//     bool solve(int ind , string s ,int n , vector<int> &dp){
//         if(ind >= n){
//             return true;
//         }
//         if(st.find(s) != st.end()){
//             return true;
//         }
        
//         if(dp[ind]!=-1) return dp[ind];
        
//         for(int l=1 ; l<=s.size(); l++){
            
//             string temp = s.substr(ind,l);
            
//             if(st.find(temp)!=st.end() && solve(ind+l,s,n,dp) ){
//                 return dp[ind]=true;
//             }
//         }
        
//         return dp[ind]=false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//        int n = s.size();
        
//         for(string word : wordDict){
//             st.insert(word);
//         }
        
//         vector<int> dp(n+1,false);
//       // return solve(0,s,n,dp);
//         dp[0]=true;
        
//         for(int i=1 ; i<=s.size() ; i++){
//             for(int j=0; j<=i ; j++){
//                  string temp = s.substr(j,i-j);
            
//             if(st.find(temp)!=st.end() &&  ){
//                 return dp[ind]=true;
//             }
//             }
//         }
//     }
// };
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                string temp = s.substr(j, i - j);
                if (dp[j] && st.find(temp) != st.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};