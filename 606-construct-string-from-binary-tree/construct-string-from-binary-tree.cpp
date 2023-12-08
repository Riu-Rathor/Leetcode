/*
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
    void solve(TreeNode* root, string &ans) {
        if(!root) {
            return;
        }

        ans.push_back(root->val + '0');
        if(root->left) {
            ans.push_back('(');
            solve(root->left, ans);
            ans.push_back(')');
        }
        else if(root->right) {
            if(!root->left) {
                ans += "()";
            }
            ans.push_back('(');
            solve(root->right, ans);
            ans.push_back(')');
        }
    }
    string tree2str(TreeNode* root) {
        // string ans = "";
        // solve(root, ans);
        // return ans;
        if(root == NULL) {
            return "";
        }

        string ans = to_string(root->val);
        string Left = tree2str(root->left);
        string Right = tree2str(root->right);

        if(!root->left && !root->right) {
            return ans;
        }
        if(root->left == NULL) {
            return ans + "()" + "(" + Right + ")";
        }

        if(root->right == NULL) {
            return ans + "(" + Left + ")";
        }

        return ans + "(" + Left + ")" + "(" + Right + ")";

    }
};