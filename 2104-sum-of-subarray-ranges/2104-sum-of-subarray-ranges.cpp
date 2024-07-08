class Solution {
public:
    long long calculateMinRanges(vector<int> nums){ //increasing stack
        
        int n = nums.size();
        
        stack<int> st;
        long long sum = 0;
        
        for(int i=0 ; i<=n ; i++){
            
            while(!st.empty() &&( (i==nums.size()) || nums[st.top()] > nums[i] ) ){
                
                int curr_i = st.top();
                st.pop();
                int prev_min = (st.empty()) ? -1 : st.top();
                sum += (curr_i-prev_min)*(i-curr_i)*(long long)nums[curr_i];
            }
                st.push(i);
            
        }
        
        return sum;
    }
    long long calculateMaxRanges(vector<int> nums){ //decreasing stack
        
        int n = nums.size();
        
        stack<int> st;
        long long sum = 0;
        
        for(int i=0 ; i<=n ; i++){
            
            while(!st.empty() && ((i == n) || nums[st.top()] < nums[i]) ){
                
                int curr_i = st.top();
                st.pop();
                int prev_max = (st.empty()) ? -1 : st.top();
                sum += (curr_i-prev_max)*(i-curr_i)*(long long)nums[curr_i];
            }
                st.push(i);
            }
        
        
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long maxRangeSums = calculateMaxRanges(nums);
        long long minRangeSums = calculateMinRanges(nums);
        
        return maxRangeSums-minRangeSums;
    }
};