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
    void solve(TreeNode* root, int &count, int val) {
        if(!root) {
            return;
        }
        val = val ^ (1 << root->val);
        if(!root->left && !root->right) {
            if((val & (val - 1)) == 0) {
                count++;
            }
        }
        solve(root->left, count, val);
        solve(root->right, count, val);

    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        vector<int> freq(10, 0);
        solve(root, count, 0);
        return count;
    }
};