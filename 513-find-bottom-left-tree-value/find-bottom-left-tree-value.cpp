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

    void solve(TreeNode* root, int &level, int depth, int &ans) {
        if(!root) {
            return;
        }
        solve(root->left, level, depth + 1, ans);
        if(depth > level) {
            ans = root->val;
            level = depth;
        }
        solve(root->right, level, depth + 1, ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        int level = 0;
        solve(root, level, 1, ans);
        return ans;
    }
};