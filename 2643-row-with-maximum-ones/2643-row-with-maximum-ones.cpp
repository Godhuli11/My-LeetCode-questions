class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int row_ind=0;
        int max_cnt=0;
        int m = mat.size();
        int n = mat[0].size();
        
       
        
        for(int i=0 ; i<m ; i++){
            int cnt = 0;
            
            for(int j=0 ; j<n ; j++){
                if(mat[i][j]==1){
                    cnt++;
                }
            }
            
            if(cnt>max_cnt){
                max_cnt = cnt;
                row_ind = i;
            }
        }
        
           ans.push_back(row_ind);
           ans.push_back(max_cnt);
        return ans;
            
    }
};