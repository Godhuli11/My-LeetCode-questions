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
    int leftHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        
        return 1 + leftHeight(root->left);
    }
     int rightHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        
        return 1 + rightHeight(root->right);
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        
        int lH = leftHeight(root);
        int rH = rightHeight(root);
        
        if(lH == rH){  //perfect binary tree
            return (pow(2,lH)-1); //perfect binary tree property
        }else{
            return countNodes(root->left) + countNodes(root->right)+1;
        }
    }
};