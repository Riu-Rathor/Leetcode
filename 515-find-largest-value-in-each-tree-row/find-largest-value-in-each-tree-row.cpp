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

    void solve(TreeNode* root, vector<int> &result, int depth) {
        if(!root) {
            return;
        }

        if(depth == result.size()) {
            result.push_back(root->val);
        }
        else {
            result[depth] = max(result[depth], root->val);
        }
        solve(root->left, result, depth+1);
        solve(root->right, result, depth+1);

    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) {
            return {};
        }
        vector<int> result;
        solve(root, result, 0);
        return result;
        
    }
};