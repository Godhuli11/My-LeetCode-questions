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
    void solve(TreeNode* root , int val , int& res){
        if(!root){
            return;
        }
        
        val = val ^ (1 << root->val);
        
        if(!root->left && !root->right){
            
            if((val & (val-1)) == 0){ //if there is only 1 set bit ie only 1 oddFreq
                res += 1;
            }
        }
        
        solve(root->left , val , res);
        solve(root->right , val , res);
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        
        int res = 0;
        
        solve(root , 0 , res);
        
        return res;
    }
};