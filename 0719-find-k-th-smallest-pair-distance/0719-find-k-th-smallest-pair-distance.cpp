class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        vector<int> arr(n*(n-1)/2);
        
        int idx =  0;
        for(int i=0 ; i<n ; i++){
            for(int j=i + 1; j<n ; j++){
                
                int d = abs(nums[i] - nums[j]);
                
                arr[idx] = d;
                idx++;
            }
        }
        
        nth_element(arr.begin(),arr.begin() + k-1 , arr.end());
        
        return arr[k-1];
    }
};