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
    long SUM;
    long maxP=0;
    
    long calcSum(TreeNode* root){
        if(!root){
            return 0;
        }
        
        long leftSum = calcSum(root->left);
        long rightSum = calcSum(root->right);
        
        long subTreeSum = root->val + leftSum + rightSum;
        
        long remaining = SUM - subTreeSum;
        
        maxP = max(maxP , subTreeSum * remaining);
        
        return subTreeSum;
    }
    
    int maxProduct(TreeNode* root) {
        if(!root){
            return 0;
        }
        
       SUM = calcSum(root);//total tree sum
        
       calcSum(root);
        
       return maxP%(1000000007);
        
    }
};