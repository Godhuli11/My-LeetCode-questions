class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        sort(nums.begin(), nums.end());
        int moves = 0, prev = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] <= prev) {
                moves += prev - nums[i] + 1;
                prev = prev + 1;
            } else {
                prev = nums[i];
            }
        }
        
        return moves;
    }
};
