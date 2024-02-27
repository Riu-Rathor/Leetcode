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

    int heightOfTree(TreeNode* root, int &ans) {
        if(!root) {
            return 0;
        }
        int leftAns = heightOfTree(root->left, ans);
        int rightAns = heightOfTree(root->right, ans);
        ans = max(ans, leftAns + rightAns);
        return 1 + max(leftAns, rightAns);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int ans = INT_MIN;
        heightOfTree(root, ans);
        return ans;
    }
};