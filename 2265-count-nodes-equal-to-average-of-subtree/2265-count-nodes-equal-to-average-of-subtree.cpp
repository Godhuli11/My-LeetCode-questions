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
    pair<int,int> solve(TreeNode* root , int& res){
        if(!root){
            return {0,0};
        }
        
        auto lp = solve(root->left , res);
        auto rp = solve(root->right , res);
        
        int sum = root->val + lp.first + rp.first;
        int cnt = 1 + lp.second + rp.second;
        
        if(abs(sum / cnt) == root->val){
            res++;
        }
        return {sum , cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        int res=0;
        solve(root,res);
        return res;
    }
};