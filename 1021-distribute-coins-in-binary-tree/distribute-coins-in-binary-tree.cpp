/**
 * Definition for a binary tree node.
 * struct TreeNode {+ 
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int solve(TreeNode* root, int &steps) {
        if(!root) {
            return 0;
        }

        int left_ans = solve(root->left, steps);
        int right_ans = solve(root->right, steps);
        steps += abs(left_ans) + abs(right_ans);
        return left_ans + right_ans + root->val - 1;
    }
public:
    int distributeCoins(TreeNode* root) {
        int steps = 0;
        solve(root, steps);
        return steps;
    }
};