class Solution {
public:
     int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create an adjacency list to represent the directed graph
        vector<vector<pair<int, int>>> adj(n + 1);

        // Populate the adjacency list
        for (auto& time : times) {
            int u = time[0];
            int v = time[1];
            int wt = time[2];
            adj[u].push_back({v, wt});
        }

        // Priority queue to store {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Vector to store minimum distances from source to each node
        vector<int> dist(n + 1, INT_MAX);

        // Push the source node into the heap with distance 0
        minHeap.push({0, k});
        dist[k] = 0;

        while (!minHeap.empty()) {
            int currNode = minHeap.top().second;
            int currDist = minHeap.top().first;
            minHeap.pop();

            // Explore neighbors of the current node
            for (auto& neighbor : adj[currNode]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                // Relaxation step
                if (dist[currNode] + edgeWeight < dist[nextNode]) {
                    dist[nextNode] = dist[currNode] + edgeWeight;
                    minHeap.push({dist[nextNode], nextNode});
                }
            }
        }

        // Find the maximum distance from source to any other node
        int maxDist = *max_element(dist.begin() + 1, dist.end());

        // Check if all nodes are reachable
        return (maxDist == INT_MAX) ? -1 : maxDist;
    }

};