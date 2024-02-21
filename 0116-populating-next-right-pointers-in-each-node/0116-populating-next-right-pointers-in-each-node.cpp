/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve(Node* root){
        if(root==NULL||root->left == NULL) return;
        
        Node* leftChild = root->left;
        Node* rightChild = root->right;
        
        leftChild->next = rightChild;
        if(root->next){
            rightChild->next = root->next->left;
        }else{
            rightChild->next = NULL;
        }
        
        solve(leftChild);
        solve(rightChild);
        
    }
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};