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
    void solve(TreeNode* root, vector<int> &leaves) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            leaves.push_back(root->val);
        }
        solve(root->left, leaves);
        solve(root->right, leaves);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2) {
            return false;
        }
        vector<int> leaves1;
        vector<int> leaves2;
        solve(root1, leaves1);
        solve(root2, leaves2);
        return leaves1 == leaves2;
    }
};