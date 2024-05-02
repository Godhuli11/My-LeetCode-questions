class Solution {
public:
    int findMax(vector<vector<int>>& mat , int r ,  int mid){
        
        int val = INT_MIN;
        int ans = 0;
        
        for(int i=0 ; i<r ; i++){
            if(mat[i][mid] > val){
                val = mat[i][mid];
                ans = i;
            }
        }
        
        return ans;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        
        int r = mat.size();
        int c = mat[0].size();
        
        int low = 0;
        int high = c-1;
        
        while(low <= high){
            int mid = (low + high)/2;
            
            int row = findMax(mat,r,mid);
            
             int left = mid-1 >= 0 ? mat[row][mid-1] : -1;
             int right = mid+1 < c ? mat[row][mid+1] : -1;
            
            if(mat[row][mid] > left && mat[row][mid] > right){
                return {row,mid};
            }else if( mat[row][mid] < left){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        return {-1,-1};
    }
};