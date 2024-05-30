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

    bool solve(TreeNode* root, int level, vector<int> &levelPrev) {
        if(!root) {
            return true;
        }

        if((level % 2 == 0 && root->val % 2 == 0) || (level % 2 != 0 && root->val % 2 != 0)) {
            return false;
        }

        if(level >= levelPrev.size()) {
            levelPrev.resize(level+1);
        }

        if(levelPrev[level] != 0) {
            if(level % 2 == 0 && root->val <= levelPrev[level]) {
                return false;
            }

            if(level % 2 != 0 && root->val >= levelPrev[level]) {
                return false;
            }
        }
        levelPrev[level] = root->val;
        return solve(root->left, level+1, levelPrev) && solve(root->right, level+1, levelPrev);

    }
public:
    bool isEvenOddTree(TreeNode* root) {
        vector<int> levelPrev;
        return solve(root, 0, levelPrev);
    }
};