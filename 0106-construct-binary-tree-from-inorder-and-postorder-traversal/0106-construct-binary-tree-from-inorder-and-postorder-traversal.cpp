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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder , int inStart ,int inEnd ,int poStart , int posEnd){
        
        if(inStart > inEnd || poStart > posEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[posEnd]);
        
        int root_candidate = root->val;
        
        int i=inStart;
        
        for( ; i<= inEnd ; i++){
            if(inorder[i]==root_candidate){
                break;
            }
        }
        
        int left_size = i-inStart;
        int right_size = inEnd-i;
        
        root->left = solve(inorder,postorder,inStart,i-1,poStart,poStart+left_size-1);
        root->right = solve(inorder,postorder,i+1,inEnd,posEnd-right_size,posEnd-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        
        TreeNode* root = NULL;
        
        int inStart = 0;
        int inEnd = n-1;
        
        int poStart = 0;
        int posEnd = n-1;
        
       root =  solve( inorder, postorder ,  inStart , inEnd , poStart , posEnd);
           
       return root;
        
    }
};