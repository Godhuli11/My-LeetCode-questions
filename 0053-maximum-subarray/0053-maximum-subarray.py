class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        cursum = 0
        maxsum = nums[0]  # Initialize maxsum to the first element to handle arrays with negative numbers
        
        for i in nums:
            cursum += i
            maxsum = max(maxsum, cursum)
            if cursum < 0:
                cursum = 0
        return maxsum