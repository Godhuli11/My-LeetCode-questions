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
// class Solution {
// public:
//     TreeNode* solve(vector<int>& preorder , int start , int end , int size){
//         if(start > end){
//             return NULL;
//         }
//         TreeNode* root = new TreeNode(preorder[start]);
//         int i = start;
//         for( ; i <= end ; i++){
//             if(preorder[i]>preorder[start]){
//                 break;
//             }
//         }
//         end = i-1;
//         root->left = solve(preorder , start+1 , end , size );
//         root->right = solve(preorder , i , size , size);
//         return root;
//     }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int n = preorder.size();
//         return solve(preorder , 0 , n-1 , n);
//     }
// };
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
    TreeNode* solve(vector<int>& preorder, int& start, int end, int size) {
        if (start > end) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[start]);
        int i = start;
        for (; i <= end; i++) {
            if (preorder[i] > preorder[start]) {
                break;
            }
        }

        start++;  // Move to the next element in preorder

        root->left = solve(preorder, start, i - 1, size);
        root->right = solve(preorder, i, end, size);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        int start = 0;
        return solve(preorder, start, n - 1, n);
    }
};
