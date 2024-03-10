class Solution {
public:
    void solve(vector<vector<int>>& matrix , int m , int n , int r , int c , int dr , int dc ,  vector<int>& ans){
        
        if(m==0 || n==0){
            return;
        }
        
        for(int i=0 ; i<n ; i++){
            
            r = r + dr;
            c = c + dc;
            
            ans.push_back(matrix[r][c]);
            
        }
        
        solve(matrix,n,m-1,r,c,dc,-dr,ans);
        
    }
        
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> ans;
        
        solve(matrix , m , n , 0 , -1 , 0 , 1 , ans);
        
        return ans;
    }
};