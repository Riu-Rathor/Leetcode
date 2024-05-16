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

    int solve(TreeNode* root, int curr) {
        if(!root) {
            return 0;
        }

        curr = curr * 10 + root->val; 
        if(!root->left && !root->right) {
            return curr;
        }
        return solve(root->left, curr) + solve(root->right, curr);

    }
public:
    int sumNumbers(TreeNode* root) {
        int result = 0;
        int num = 0;
        return solve(root, num);
    }
};