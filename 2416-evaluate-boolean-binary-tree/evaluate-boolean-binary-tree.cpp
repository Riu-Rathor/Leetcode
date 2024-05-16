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
public:
    bool evaluateTree(TreeNode* root) {
        if(!root) {
            return true;
        }

        if(!root->left && !root->right) {
            if(root->val == 1) {
                return true;
            }
            else if(root->val == 0) {
                return false;
            }
        }

        bool left_ans = evaluateTree(root->left);
        bool right_ans = evaluateTree(root->right);

        if(root->val == 2) {
            return left_ans || right_ans;
        }

        return left_ans && right_ans;
    }
};