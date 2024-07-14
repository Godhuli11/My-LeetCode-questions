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
    void solve(TreeNode* root , bool goLeft , int& maxPath , int steps){
        if(!root){
            return;
        }
        
        maxPath = max(maxPath , steps);
        
        if(goLeft){
            solve(root->left , false , maxPath , steps+1);
            solve(root->right , true , maxPath , 1);
        }else{
            solve(root->left , false , maxPath , 1);
            solve(root->right , true , maxPath , steps+1);
        }
        
        
    }
    int longestZigZag(TreeNode* root) {
        int maxPath = 0;
        int steps = 0;
         solve(root,true,maxPath,steps);
         solve(root,false,maxPath,steps);
        
        return maxPath;
    }
};
// class Solution {
// public:
//     void solve(TreeNode* root, bool goLeft, int& maxPath, int steps) {
//         if (!root) {
//             return;
//         }

//         maxPath = max(maxPath, steps);

//         if (goLeft) {
//             if (root->left) solve(root->left, false, maxPath, steps + 1); // Continue to left with increased steps
//             if (root->right) solve(root->right, true, maxPath, 1);         // Start new path to the right with 1 step
//         } else {
//             if (root->right) solve(root->right, true, maxPath, steps + 1); // Continue to right with increased steps
//             if (root->left) solve(root->left, false, maxPath, 1);          // Start new path to the left with 1 step
//         }
//     }

//     int longestZigZag(TreeNode* root) {
//         int maxPath = 0;
//         if (root->left) solve(root->left, false, maxPath, 1);  // Initial call to left with 1 step
//         if (root->right) solve(root->right, true, maxPath, 1); // Initial call to right with 1 step

//         return maxPath;
//     }
// };
