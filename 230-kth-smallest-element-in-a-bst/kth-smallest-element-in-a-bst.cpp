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
    void solve(TreeNode* root, int &cnt, int k, int &ans) {
        if(!root) {
            return;
        }
        solve(root->left, cnt, k, ans);
        cnt++;
        if(cnt == k) {
            ans = root->val;
            return;
        }
        solve(root->right, cnt, k, ans);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root->left && !root->right) {
            return root->val;
        }
        int ans;
        int cnt = 0;
        solve(root, cnt, k, ans);
        return ans; 
    }
};