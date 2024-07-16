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
    TreeNode* LCA(TreeNode* root, int src, int dest) {
        if(!root) {
            return NULL;
        }

        if(root->val == src || root->val == dest) {
            return root;
        }

        TreeNode* l = LCA(root->left, src, dest);
        TreeNode* r = LCA(root->right, src, dest);

        if(l && r) {
            return root;
        }
        return l ? l : r;
    }

    bool findPath(TreeNode* lca, int target, string &path) {
        if(lca == NULL) {
            return false;
        }

        if(lca->val == target) {
            return true;
        }

        path.push_back('L');
        if(findPath(lca->left, target, path)) {
            return true;
        }

        path.pop_back();

        path.push_back('R');
        if(findPath(lca->right, target, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lca = LCA(root, startValue, destValue);
        string lcaToSrc = "";
        string lcaToDest = "";

        findPath(lca, startValue, lcaToSrc);
        findPath(lca, destValue, lcaToDest);

        string result = "";
        for(int i=0; i<lcaToSrc.length(); i++) {
            result.push_back('U');
        }
        result += lcaToDest;
        return result;
    }
};