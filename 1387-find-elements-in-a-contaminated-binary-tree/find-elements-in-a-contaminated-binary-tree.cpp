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
class FindElements {
    unordered_set<int> st;
    void dfs(TreeNode* root, int x) {
        if(!root) {
            return;
        }

        root->val = x;
        st.insert(x);
        dfs(root->left, 2*x+1);
        dfs(root->right, 2*x+2);
    }
public:
    FindElements(TreeNode* root) {
        st.clear();
        dfs(root, 0);
    }
    
    bool find(int target) {
        if(st.find(target) != st.end()) {
            return true;
        }
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */