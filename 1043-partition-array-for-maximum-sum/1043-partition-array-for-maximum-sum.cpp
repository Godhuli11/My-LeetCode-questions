

class Solution {
public:
    int t[501];
    int solve(int i, vector<int>& arr, int k) {
        if (i >= arr.size()) {
            return 0;
        }
        if(t[i]!=-1) return t[i];
        int max_curr = -1;
        int res = 0;
        for (int j = i; j < arr.size() && j - i + 1 <= k; j++) {
            max_curr = max(max_curr, arr[j]);  // Update max_curr based on the current window
            res = max(res, max_curr * (j - i + 1) + solve(j + 1, arr, k));
        }
        t[i] = res;
        return t[i];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(t,-1,sizeof(t));
        return solve(0, arr, k);
    }
};