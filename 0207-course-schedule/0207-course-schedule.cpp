class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        for (auto& prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
            inDegree[prerequisite[0]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int visitedCount = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            visitedCount++;

            for (int neighbor : adj[current]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return visitedCount == n;
    }
};
