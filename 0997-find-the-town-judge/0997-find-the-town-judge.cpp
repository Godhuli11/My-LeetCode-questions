class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        vector<int> count(n+1,0);
        
        int ans = -1;
        
        for(auto &vec : trust){
            
            int out = vec[0];
            int in = vec[1];
            
            count[out]--;
            count[in]++;
        }
        
        for(int i=0 ; i<count.size() ; i++){
            if(count[i]==n-1){
                ans = i;
            }
        }
        
        return ans;
    }
};