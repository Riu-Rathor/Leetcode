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
    void solve(TreeNode* root, string path, vector<string> &ans) {
        if(!root) {
            return;
        }
 
        if(!root->left && !root->right) {
            path += to_string(root->val);
            ans.push_back(path);
            return;
        }
        path += to_string(root->val) + "->";
        solve(root->left, path, ans);
        solve(root->right, path, ans);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string path = "";
        solve(root, path, ans);
        return ans;
    }
};