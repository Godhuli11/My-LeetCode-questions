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
    void fill(TreeNode* root, int& targetSum , int sum , vector<int> temp , vector<vector<int>>& ans){
        if(!root){
            return;
        }
        
        sum += root->val;
        temp.push_back(root->val);
        
        if(!root->left && !root->right){
            if(sum == targetSum){
                ans.push_back(temp);
            }
             return;
        }
        
        fill(root->left , targetSum , sum , temp , ans);
        fill(root->right , targetSum , sum , temp , ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> temp;
        
        vector<vector<int>> ans;
        
        int sum = 0;
        
        fill(root,targetSum,sum,temp,ans);
        
        return ans;
    }
};