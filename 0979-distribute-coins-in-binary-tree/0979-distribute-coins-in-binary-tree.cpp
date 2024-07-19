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
    int solve(TreeNode* root , int& minMoves){
        if(!root){
            return 0;
        }
        
        int l = solve(root->left , minMoves);
        int r = solve(root->right , minMoves);
        
        minMoves += abs(l) + abs(r);
        
        return l + r + root->val - 1;
    }
    int distributeCoins(TreeNode* root) {
        
        int minMoves = 0;
        solve(root,minMoves);
        return minMoves;
    }
};