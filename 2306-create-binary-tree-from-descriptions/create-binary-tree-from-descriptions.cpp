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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> st;
        int n = descriptions.size();
        for(int i=0; i<n; i++) {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];

            st.insert(child);
            if(mp.find(parent) == mp.end()) {
                TreeNode* newNode = new TreeNode(parent);
                mp[parent] = newNode;
            }

            if(mp.find(child) == mp.end()) {
                TreeNode* newNode = new TreeNode(child);
                mp[child] = newNode;
            }

            if(isLeft) {
                mp[parent]->left = mp[child];
            }
            else {
                mp[parent]->right = mp[child];
            }
        }

        for(int i=0; i<n; i++) {
            if(st.find(descriptions[i][0]) == st.end()) {
                return mp[descriptions[i][0]];
            }
        }
        return NULL;
    }
};