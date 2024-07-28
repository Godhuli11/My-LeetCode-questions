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
    
    void dfs(TreeNode* root , string temp , string& res){
        if(!root){
            return;
        }
        
        temp = char(root->val + 'a') + temp;
        
        if(!root->left && !root->right){
                 if(res == "" || res > temp){
            res = temp;
        }
        }
        
        dfs(root->left,temp,res);
        dfs(root->right,temp,res);
        
    }
    string smallestFromLeaf(TreeNode* root) {
             string res = "";
             string temp = "";
             dfs(root,temp,res);
             return res;
    }
};