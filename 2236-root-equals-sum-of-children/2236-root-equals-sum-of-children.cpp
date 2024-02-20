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
    bool solve(TreeNode* root){
        if(root==NULL){
            return true;
        }
        if(!root->left && !root->right){
            return true;
        }
        int sum=0;
        if(root->right){
            sum += root->right->val;
        }
        if(root->left){
            sum += root->left->val;
        }
        
        if((root->val == sum ) && solve(root->right) && solve(root->left)){
            return true;
        }else{
            return false;
        }
        
    }
    bool checkTree(TreeNode* root) {
       return solve(root);
    }
};