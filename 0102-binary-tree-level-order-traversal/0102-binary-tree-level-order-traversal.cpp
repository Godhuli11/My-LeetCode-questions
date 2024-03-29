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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        
        queue<TreeNode*> q;
        vector<int> temp;
        vector<vector<int>> ans;
        
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            temp = {};
            while(size--){
                TreeNode* p = q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->left){
                    q.push(p->left);
                }
                 if(p->right){
                    q.push(p->right);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};