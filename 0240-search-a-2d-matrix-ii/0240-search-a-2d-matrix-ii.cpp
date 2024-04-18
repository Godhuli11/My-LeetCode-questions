class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        int r=0;
        int c=n-1;
        
        while(r<m && c>=0){
            if(mat[r][c]==target){
                return true;
            }else if(mat[r][c]<target){
                r++;
            }else{
                c--;
            }
        }
        
        return false;
    }
};