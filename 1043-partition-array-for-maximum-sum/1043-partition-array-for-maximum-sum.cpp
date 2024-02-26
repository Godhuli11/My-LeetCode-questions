class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        
        vector<int> t(n+1);
        
        for(int size = 1 ; size <= n ; size++){
            int max_curr = -1;
            
            for(int j=1 ; j<=k && size-j >= 0 ; j++){
                max_curr = max(max_curr , arr[size-j]);
                t[size] = max(t[size] , max_curr*(j) + t[size-j]);
            }
        }
        
        return t[n];
    }
};