class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
              sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int current_end = INT_MIN;  // Initialize current_end to the smallest possible value
        int longest_chain = 0;  // Initialize the length of the longest chain
        
        for (const auto& pair : pairs) {
            // If the start of the current pair is greater than the end of the last selected pair
            if (pair[0] > current_end) {
                current_end = pair[1];  // Update the end to the end of the current pair
                longest_chain++;  // Increase the count of the longest chain
            }
        }
        
        return longest_chain;
    }

};