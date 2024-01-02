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
    // int solve(TreeNode* root) {
    //     if(!root) {
    //         return 0;
    //     }

    //     // int ans = INT_MAX;
    //     int leftAns = solve(root->left);
    //     int rightAns = solve(root->right);
    //     return 1 + min(leftAns, rightAns);

    // }
public:
    int minDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }

        queue<TreeNode*> q;
        int depth = 1;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();

            while(n--) {
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left == NULL && temp->right == NULL) {
                    return depth;
                } 
                if(temp->left) {
                    q.push(temp->left);
                }

                if(temp->right) {
                    q.push(temp->right);
                }
            } 
            depth++;
        }
       return -1;
    }
};