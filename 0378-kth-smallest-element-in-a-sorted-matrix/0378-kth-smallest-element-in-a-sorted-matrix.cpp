class Solution {
public:
    // Function to count elements <= val in a single row using binary search
    int bsRows(vector<int>& row, int val) {
        int n = row.size();
        int low = 0;
        int high = n - 1;
        int cnt = 0;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            if (row[mid] <= val) {
                cnt = mid + 1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return cnt;
    }

    // Function to count elements <= mid in the entire matrix
    int count(vector<vector<int>>& matrix, int mid, int n) {
        int cnt = 0;
        
        for (int i = 0; i < n; i++) {
            cnt += bsRows(matrix[i], mid);
        }
        
        return cnt;
    }
    
    // Function to find the k-th smallest element in the matrix
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int res=-1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int numOfSmaller = count(matrix, mid, n);

            if (numOfSmaller < k) {
                low = mid + 1;
            } else { //numOfSmaller >= k
                res = mid;
                high = mid - 1;
            }
        }
        
        return res;
    }
};
