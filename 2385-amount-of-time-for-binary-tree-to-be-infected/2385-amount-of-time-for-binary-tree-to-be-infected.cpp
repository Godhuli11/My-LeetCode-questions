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
     int bfsTofindmax(map<TreeNode*,TreeNode*> &map,TreeNode*target){
    queue<TreeNode*> q;
    q.push(target);
    unordered_map<TreeNode*,int>vis;
    vis[target]=1;
    int timer = 0;
    while(!q.empty()){
        int size = q.size();
        int flag = 0;
        for(int i = 0;i<size;i++){
            auto node = q.front();
            q.pop();
            if(node->left && vis[node->left]!=1){
                flag = 1;
                vis[node->left]=1;
                q.push(node->left);
            }
            if(node->right && vis[node->right]!=1){
                flag = 1;
                vis[node->right]=1;
                q.push(node->right);
            }
            if(map[node] && vis[map[node]]!=1){
                flag = 1;
                vis[map[node]]=1;
                q.push(map[node]);
            }
        }
        if(flag)timer++;
    }
    return timer;
}
TreeNode* bfsToMapParents(TreeNode* root,int start, map<TreeNode*,TreeNode*>&map){
         queue<TreeNode*> q;
         q.push(root);
         TreeNode*res;
         while(!q.empty()){
             TreeNode* node = q.front();
             q.pop();
             if(node->val == start)res=node;
             if(node->left){
                 map[node->left]=node;
                 q.push(node->left);
             }
              if(node->right){
                 map[node->right]=node;
                 q.push(node->right);
             }
         }
         return res;
}
int amountOfTime(TreeNode* root, int start)
{
    map<TreeNode*,TreeNode*>mpp;  //child,parent
    TreeNode* target = bfsToMapParents(root,start,mpp);
    int maxitime = bfsTofindmax(mpp,target);
    return maxitime;
}
};