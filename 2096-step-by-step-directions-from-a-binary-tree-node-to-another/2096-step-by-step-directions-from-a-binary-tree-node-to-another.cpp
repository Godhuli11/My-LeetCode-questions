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
    bool path(TreeNode* root , int target , string& s){
        
        if(!root) return false;
        
        if(root->val == target) return true;
        
        s.push_back('L');
        if(path(root->left , target , s)){
            return true;
        }
        s.pop_back();
        
        s.push_back('R');
        if(path(root->right , target , s)){
            return true;
        }
        s.pop_back();
      
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string rootToSrc = "";
        string rootToDest = "";
        string ans = "";
        
        path(root,startValue,rootToSrc);
        path(root,destValue,rootToDest);
        
        int ptr = 0;
        
        while(ptr < rootToSrc.size() && ptr < rootToDest.size() && rootToSrc[ptr] == rootToDest[ptr]){
            ptr++;
        }
        
        for(int i=0 ; i<rootToSrc.size()-ptr ; i++){
            ans.push_back('U');
        }
        
        for(int i=ptr ; i<rootToDest.size() ; i++){
            ans.push_back(rootToDest[i]);
        }
        
        return ans;
        
    }
};