#include <vector>
#include <string>

class Solution {
public:
    class TrieNode {
    public:
        vector<TrieNode*> children;

        // Change this to store the complete word
        string fullWord;

        TrieNode() : children(26, nullptr), fullWord("") {}
    };

    void insert(TrieNode* root, const string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }

        // Store the complete word at the end node
        curr->fullWord = s;
    }

    string ans = "";

    void dfs(TrieNode* root) {
        for (auto child : root->children) {
            if (child && !child->fullWord.empty()) {
                if (child->fullWord.size() > ans.size() ||
                    (child->fullWord.size() == ans.size() && child->fullWord < ans)) {
                    ans = child->fullWord;
                }

                dfs(child);
            }
        }
    }

    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (const string& s : words) {
            insert(root, s);
        }

        dfs(root);

        return ans;
    }
};
