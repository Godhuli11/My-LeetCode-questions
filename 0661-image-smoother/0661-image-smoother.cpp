class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        
        vector<int> temp(n);
        int prevCorner = 0;
        
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){
                
                int sum = 0;
                int cnt = 0;
                
                if(i+1 < m){
                    
                    if(j-1 >=0){
                        sum += img[i+1][j-1];
                        cnt++;
                    }
                    sum += img[i+1][j];
                    cnt++;
                    if(j+1 < n){
                        sum += img[i+1][j+1];
                        cnt++;
                    }
                }
                
                if(j+1 < n){
                    sum += img[i][j+1];
                    cnt++;
                }
                
                sum += img[i][j];
                cnt++;
                
                if(j-1 >=0){
                    sum += temp[j-1];
                    cnt++;
                }
                
                if(i-1 >=0){
                    if(j-1 >=0){
                        sum += prevCorner;
                        cnt++;
                    }
                    
                    sum += temp[j];
                    cnt++;
                    
                    if(j+1 < n){
                        sum += temp[j+1];
                        cnt++;
                    }
                }
                    if (i - 1 >= 0) {
                    prevCorner = temp[j];
                }

                // Store current value
                temp[j] = img[i][j];

                // Overwrite with smoothed value.
                img[i][j] = sum / cnt;
            }
        }

        // Return the smooth image.
        return img;
    
            
        
    }
};