class Solution {
public:
    int countOverLaps(vector<vector<int>>& A, vector<vector<int>>& B , int rowOff, int colOff , int n){
        int cnt = 0;
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                
                int B_i = i + rowOff;
                int B_j = j+colOff;
                
                if(B_i >= n || B_i < 0 || B_j >= n || B_j < 0){
                    continue;
                }
                
                if(A[i][j] == 1 && B[B_i][B_j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        int n = A.size();
        
        int maxOverlap = 0;
        
        for( int rowOff = -n+1 ; rowOff < n ; rowOff++){
            for( int colOff = -n+1 ; colOff < n ; colOff++){
                maxOverlap = max(maxOverlap , countOverLaps(A,B,rowOff,colOff,n));
            }
        }
        
        return maxOverlap ;
    }
};