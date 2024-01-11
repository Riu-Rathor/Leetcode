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
    int findMaxDiff(TreeNode* root, int mini, int maxi) {
        if(!root) {
            return abs(mini - maxi);
        }

        mini = min(mini, root->val);
        maxi = max(maxi, root->val);
        int leftAns = findMaxDiff(root->left, mini, maxi);
        int rightAns = findMaxDiff(root->right, mini, maxi);
        return max(leftAns, rightAns);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int mini = root->val;
        int maxi = root->val;
        return findMaxDiff(root, mini, maxi);
    }
};