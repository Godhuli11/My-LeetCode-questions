class Solution {
public:
    int findDays(vector<int>& weights, int mid , int n){
        int days = 1;
        int currWeight = 0;
        for(int i=0 ; i<n ; i++){
            if(currWeight + weights[i] <= mid){
                currWeight += weights[i];
            }else{
                days++;
                currWeight = weights[i];
            }
        }
        
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n = weights.size();
        
        int low = INT_MIN;
        
        int high = accumulate(weights.begin(),weights.end(),0);
        
        for(int i=0 ; i<n ; i++){
            low = max(weights[i],low);
        }
        
        int finalWeight = -1;
        
        while(low <= high){
            int mid = low+(high-low) / 2;
            
            int day = findDays(weights,mid,n);
            
            //if(day == days) return mid;
            
            if(day<=days){
                
                high = mid-1;
            }else{
                
                low = mid + 1;
            }
            
        }
        return low;
    }
};