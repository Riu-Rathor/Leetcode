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

    pair<int, int> solve(TreeNode* root, int &result) {
        if(!root) {
            return {0, 0};
        }

        pair<int, int> left_ans = solve(root->left, result);
        pair<int, int> right_ans = solve(root->right, result);
        int sum = left_ans.first + right_ans.first + root->val;
        int count = left_ans.second + right_ans.second + 1;
        if(sum / count == root->val) {
            result++;
        }
        return {sum, count};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int result = 0;
        solve(root, result);
        return result;
    }
};