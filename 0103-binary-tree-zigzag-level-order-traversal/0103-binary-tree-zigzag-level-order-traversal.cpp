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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        vector<int> temp;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            temp = {};
            while(size--){
                TreeNode* p = q.front();
                q.pop();
                temp.push_back(p->val);
                if(p->left){
                    q.push(p->left);
                }
                 if(p->right){
                    q.push(p->right);
                }
            }
            ans.push_back(temp);
        }
       for(int i=1 ; i<ans.size() ; i+=2){
           reverse(ans[i].begin(),ans[i].end());
       }
        return ans;
    }
};