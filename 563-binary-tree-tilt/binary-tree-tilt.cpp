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
    int solve(TreeNode* root, int &ans) {
        if(!root) {
            return 0;
        }
        int leftAns = solve(root->left, ans);
        int rightAns = solve(root->right, ans);
        ans += abs(leftAns - rightAns);
        return leftAns + rightAns + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int ans = 0;
        int sum = solve(root, ans);
        return ans;
    }
};