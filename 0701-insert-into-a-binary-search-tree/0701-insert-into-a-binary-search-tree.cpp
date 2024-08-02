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
    void solve(TreeNode* root, TreeNode* par  , int val){
        if(!root){
            if(par->val < val){
                par->right = new TreeNode(val);
            }else{
                par->left = new TreeNode(val);
            }
            
            return;
        }
        
        if(root->val > val){
            solve(root->left , root , val);
        }else{
            solve(root->right , root , val);
       }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root){
            return new TreeNode(val);
        }
        solve(root ,NULL, val);
        return root;
    }
};