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
    class info {
    public:
         int maxi;
         int mini;
         bool isBST;
         int sum;
    };
    info solve(TreeNode* root , int &maxSum){
        if(root==NULL){
            return {INT_MIN , INT_MAX , true , 0};
        }
        info left = solve(root->left , maxSum);
        info right = solve(root->right , maxSum);
        info curr;
        curr.sum = left.sum + right.sum + root->val;
        curr.maxi = max(root->val , right.maxi);
        curr.mini = min(root->val , left.mini);
        
        if(left.isBST && right.isBST && (right.mini > root->val) && (left.maxi < root->val)){
            curr.isBST = true;
        }else{
            curr.isBST = false;
        }
        if(curr.isBST){
            maxSum = max(maxSum , curr.sum);
        }
        
        return curr;
    }
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        info temp = solve(root,maxSum);
        return maxSum;
    }
};