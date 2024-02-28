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

    void solve(TreeNode* root, int level, int &depth, int &ans) {
        if(!root) {
            return;
        }
         if(level > depth) {
            depth = level;
            ans = root->val;
        }
        solve(root->left, level+1, depth, ans);
        solve(root->right, level+1, depth, ans);
       
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int depth = 0;
        int level = 1;
        int ans = 0;
        solve(root, level, depth, ans);
        return ans;
    }
};