class Solution {
public:
    void solve(int i, int maxSize, int sum, vector<vector<int>>& ans, vector<int> &temp) {
        // Base case: if maxSize or sum becomes negative, return as it's invalid
        if (maxSize < 0 || sum < 0) {
            return;
        }

        // If sum is 0 and maxSize is 0, we found a valid combination
        if (sum == 0 && maxSize == 0) {
            ans.push_back(temp);
            return;
        }

        // If current number exceeds 9, return as it is out of range
        if (i > 9) {
            return;
        }

        // Include the current number and proceed recursively
        temp.push_back(i);
        solve(i + 1, maxSize - 1, sum - i, ans, temp);
        
        // Backtrack and try without including the current number
        temp.pop_back();
        solve(i + 1, maxSize, sum, ans, temp);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, k, n, ans, temp);
        return ans;
    }
};
