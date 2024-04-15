class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        vector<int> missing;
        
        int i=1;
        int j=0;
        int l = 0;
        
        while(1){
            
            if( j<n && i == arr[j]){
                j++;
                i++;
            }else{
                
                l++;
                
                if(k==l){
                    return i;
                }

                i++;
                 
            }
            
        }
    }
};