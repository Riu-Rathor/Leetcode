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

    void solve(TreeNode* root, int sum, vector<int> temp, vector<vector<int>> &ans, int &target) {
        if(!root) {
            return;
        }

        sum += root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right && sum == target) {
            ans.push_back(temp);
        }

        solve(root->left, sum, temp, ans, target);
        solve(root->right, sum, temp, ans, target);
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        solve(root, sum, temp, ans, targetSum);
        return ans;
    }
};