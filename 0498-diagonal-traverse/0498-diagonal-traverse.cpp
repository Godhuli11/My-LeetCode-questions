class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        
        vector<int> ans;
        
        int n = mat.size();
        int m = mat[0].size();
        
        map<int,vector<int>> mpp;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                mpp[i+j].push_back(mat[i][j]);
            }
        }
        
        bool flip = true;
        
        for(auto &it : mpp){
            if(flip){
                reverse(it.second.begin(),it.second.end());
            }
            
            for(int i=0 ; i<it.second.size() ; i++){
                ans.push_back(it.second[i]);
            }
            
            flip = !flip;
        }
        
        return ans;
    }
};