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
    vector<int> largestValues(TreeNode* root) {
        if(!root) {
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> ans;
        int maxi = INT_MIN;
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if(front != NULL) {
                maxi = max(maxi, front->val);
            }

            if(!q.empty() && front == NULL) {
                q.push(NULL);
                ans.push_back(maxi);
                maxi = INT_MIN;
            }
            if(front && front->left) {
                q.push(front->left);
            }

            if(front && front->right) {
                q.push(front->right);
            }
        }
        ans.push_back(maxi);
        return ans;
    }
};