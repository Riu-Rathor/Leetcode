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
    void findMaxDiffUtil(TreeNode* root, TreeNode* child, int &maxDiff) {
        if(!root || !child) {
            return;
        }
        maxDiff = max(maxDiff, abs(root->val - child->val));
        findMaxDiffUtil(root, child->left, maxDiff);
        findMaxDiffUtil(root, child->right, maxDiff);
    }

    void findMaxDiff(TreeNode* root, int &maxDiff) {
        if(!root) {
            return;
        }
        findMaxDiffUtil(root, root->left, maxDiff);
        findMaxDiffUtil(root, root->right, maxDiff);
        findMaxDiff(root->left, maxDiff);
        findMaxDiff(root->right, maxDiff);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        int maxDiff = -1;
        findMaxDiff(root, maxDiff);
        return maxDiff;
    }
};