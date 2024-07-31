/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void makeGraph(TreeNode* root , TreeNode* prev ,unordered_set<TreeNode*>& st ,unordered_map<TreeNode* , vector<TreeNode*>>  & adj){
        if(!root) return ;
        
        if(!root->right && !root->left){
            st.insert(root);
        }
        
        if(prev){
            adj[prev].push_back(root);
            adj[root].push_back(prev);
        }
        
        if(root->right){
            makeGraph(root->right , root , st , adj);
        }
        
        if(root->left){
            makeGraph(root->left , root , st , adj);
        }
        
    }
    
    
      int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;

        makeGraph(root, nullptr, st, adj);

        int cnt = 0;

        for (auto leaf : st) {
            unordered_set<TreeNode*> vis;
            queue<TreeNode*> q;
            q.push(leaf);
            vis.insert(leaf);

            int level = 0; // Reset level for each BFS instance

            while (!q.empty()) {
                int size = q.size();
                if (level > distance) break;

                while (size--) {
                    TreeNode* curr = q.front();
                    q.pop();

                    if (st.find(curr) != st.end() && curr != leaf) {
                        cnt++;
                    }

                    for (auto neigh : adj[curr]) {
                        if (vis.find(neigh) == vis.end()) {
                            q.push(neigh);
                            vis.insert(neigh);
                        }
                    }
                }

                level++;
            }
        }

        return cnt / 2; // Each pair is counted twice
    }
};