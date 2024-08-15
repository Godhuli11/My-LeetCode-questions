class Solution {
public:
    // Utility function to check if it's possible to reach (n-1, m-1) from (0, 0)
    bool isPossible(int effort, vector<vector<int>>& heights, int n, int m) {
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // If we've reached the bottom-right cell
            if (x == n - 1 && y == m - 1) {
                return true;
            }

            for (auto& [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // Check bounds
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !visited[nx][ny]) {
                    int currentEffort = abs(heights[x][y] - heights[nx][ny]);
                    if (currentEffort <= effort) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        int l = 0;
        int r = INT_MAX;
        int ans = INT_MAX;

        // Binary search on the effort
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(mid, heights, n, m)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};