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
    void solve(TreeNode* root, int &count, vector<int> &freq) {
        if(!root) {
            return;
        }
        freq[root->val]++;
        if(!root->left && !root->right) {
            int oddCount = 0;
            for(int i=1; i<freq.size(); i++) {
                if(freq[i] % 2 != 0) oddCount++;
            }
            if(oddCount <= 1) count++;
        }
        solve(root->left, count, freq);
        solve(root->right, count, freq);        
        freq[root->val]--;
    }

public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        vector<int> freq(10, 0);
        solve(root, count, freq);
        return count;
    }
};