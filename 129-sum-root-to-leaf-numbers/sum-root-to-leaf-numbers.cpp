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
    void solve(TreeNode* root, int &ansSum, int sum) {
        if(!root) {
            return;
        }
        sum = sum * 10 + root->val;
        if(!root->left && !root->right) {
            ansSum += sum;
            return;
        }
        solve(root->left, ansSum, sum);
        solve(root->right, ansSum, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ansSum = 0;
        int sum = 0;
        solve(root, ansSum, sum);
        return ansSum;
    }
};