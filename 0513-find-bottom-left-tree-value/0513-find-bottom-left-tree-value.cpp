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
    void solve(TreeNode* root , int& res , int curr_depth , int& max_depth){
        if(!root){
            return;
        }
        
        if(curr_depth > max_depth){
            max_depth = curr_depth;
            res = root->val;
        }
        
        solve(root->left , res , curr_depth + 1 , max_depth);
        solve(root->right, res , curr_depth + 1 , max_depth);
    }
    int findBottomLeftValue(TreeNode* root) {
       int res;
        int max_depth = -1;
        solve(root , res , 0,max_depth);
        return res;
    }
};