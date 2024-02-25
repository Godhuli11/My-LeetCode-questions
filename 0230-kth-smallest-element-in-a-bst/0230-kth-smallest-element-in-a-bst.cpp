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
    void solve(TreeNode* root, vector<int>& temp ,int &count ,int k , int &ans){
        if(root==NULL) return;
       
        
        solve(root->left,temp,count,k,ans);
         count++;
         if(count==k){
            ans = root->val;
            return;
        }
        solve(root->right,temp,count,k,ans);
        
        
    }
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> temp;
        int count=0;
        int ans = -1;
        solve(root,temp,count,k,ans);
      
        return ans;
    }
};