// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         map<int, int> sumToCount;

//         int ans = 0;
//         int sum = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             sum += nums[i];

//             // Check if there exist a subarray with sum = k up to the current index
//             if (sum == k) {
//                 ans++;
//             }

//             // Check if there exist a subarray with sum = k by subtracting cumulative sum up to a previous index
//             int temp = sum - k;
//             if (sumToCount.find(temp) != sumToCount.end()) {
//                 ans += sumToCount[temp];
//             }

//             // Update the frequency of the current cumulative sum
//             sumToCount[sum]++;
//         }

//         return ans;
//     }
// };
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> sumToInd;
        
        int ans = 0;
        
        int sum=0 ;
        
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            int temp = sum - k;
            if(temp == 0){
                ans++;
            }
            // if(temp > 0){
            //     if(sumToInd.find(temp) != sumToInd.end()){
            //         ans+=sumToInd[temp];
            //     }
            // }
             
                if(sumToInd.find(temp) != sumToInd.end()){
                    ans+=sumToInd[temp];
                }
           
           
            sumToInd[sum]++;
        }
        
        return ans;
    }
};
