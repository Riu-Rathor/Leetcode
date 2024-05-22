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
    void solve(TreeNode* root, int depth, int &maxDepth, int &ans) {
        if(!root) {
            return;
        }

        if(depth > maxDepth) {
            maxDepth = depth;
            ans = root->val;
        }

        solve(root->left, depth+1, maxDepth, ans);
        solve(root->right, depth+1, maxDepth, ans);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = -1;
        int depth = 0;
        int ans = root->val;
        solve(root, depth, maxDepth, ans);
        return ans;
    }
};