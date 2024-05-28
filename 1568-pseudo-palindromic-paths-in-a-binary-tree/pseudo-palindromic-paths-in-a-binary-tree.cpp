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

    void solve(TreeNode* root, int &result, int count) {
        if(!root) {
            return;
        }
        count = (count ^ (1 << root->val));
        if(!root->left && !root->right) {
            if((count & (count - 1)) == 0) {
                result++;
            }
        }

        solve(root->left, result, count);
        solve(root->right, result, count);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int result = 0;
        solve(root, result, 0);
        return result;
    }
};