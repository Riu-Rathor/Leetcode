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

    void solve(TreeNode* root, int low, int high, int &result) {
        if(!root) {
            return;
        }

        if(root->val >= low && root->val <= high) {
            result += root->val;
        }

        solve(root->left, low, high, result);
        solve(root->right, low, high, result);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) {
            return 0;
        }
        int result = 0;
        solve(root, low, high, result);
        return result;
    }
};