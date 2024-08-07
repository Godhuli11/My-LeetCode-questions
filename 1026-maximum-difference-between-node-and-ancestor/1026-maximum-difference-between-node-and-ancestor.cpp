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
    int findMaxUtil(TreeNode* root , int minV , int maxV){
        if(!root){
            return abs(minV - maxV);
        }
        
        minV = min(minV , root->val);
        maxV = max(maxV , root->val);
        
        int l = findMaxUtil(root->left , minV , maxV);
        int r = findMaxUtil(root->right , minV , maxV);
        
        return max(l,r);
    }
    int maxAncestorDiff(TreeNode* root) {
        return findMaxUtil(root,root->val,root->val);
    }
};