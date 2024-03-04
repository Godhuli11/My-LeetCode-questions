class Solution {
public:
    unordered_set<string> st;
    bool solve(int ind , string s ,int n , vector<int> &dp){
        if(ind >= n){
            return true;
        }
        if(st.find(s) != st.end()){
            return true;
        }
        
        if(dp[ind]!=-1) return dp[ind];
        
        for(int l=1 ; l<=s.size(); l++){
            
            string temp = s.substr(ind,l);
            
            if(st.find(temp)!=st.end() && solve(ind+l,s,n,dp) ){
                return dp[ind]=true;
            }
        }
        
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       int n = s.size();
        
        for(string word : wordDict){
            st.insert(word);
        }
        
        vector<int> dp(n+1,-1);
       return solve(0,s,n,dp);
    }
};