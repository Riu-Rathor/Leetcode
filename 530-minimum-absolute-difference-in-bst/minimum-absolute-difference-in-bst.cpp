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
    void solve(TreeNode* root, TreeNode* &prev, int &minDiff) {
        if(!root) {
            return;
        }

        solve(root->left, prev, minDiff);
        if(prev) {
            minDiff = min(minDiff, abs(root->val - prev->val));
        }       
        prev = root;
        solve(root->right, prev, minDiff);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prev = NULL;
        solve(root, prev, minDiff);
        return minDiff;
    }
};