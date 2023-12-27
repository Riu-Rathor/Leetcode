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

    void solve(TreeNode* root, int depth, vector<int> &ans) {
        if(!root) {
            return;
        }
        if(ans.size() < depth) {
            ans.push_back(root->val);
        }
        solve(root->right, depth+1, ans);
        solve(root->left, depth+1, ans);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root, 1, ans);
        return ans;
    }
};