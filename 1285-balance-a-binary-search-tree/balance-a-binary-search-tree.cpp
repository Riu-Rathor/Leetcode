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

    void findInorder(TreeNode* root, vector<int> &inorder) {
        if(!root) {
            return;
        }

        findInorder(root->left, inorder);
        inorder.push_back(root->val);
        findInorder(root->right, inorder);
    }

    TreeNode* solve(vector<int> &inorder, int s, int e) {
        if(s > e) {
            return NULL;
        }
        int mid = s + (e - s) / 2;
        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = solve(inorder, s, mid - 1);
        root->right = solve(inorder, mid + 1, e);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        findInorder(root, inorder);
        int n = inorder.size();
        return solve(inorder, 0, n-1);
    }
};