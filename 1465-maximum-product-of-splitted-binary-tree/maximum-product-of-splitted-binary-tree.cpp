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
    long long totalSum(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return root->val + totalSum(root->left) + totalSum(root->right);
    }

    long long find(TreeNode* root, long long &maxP, long total) {
        if(!root) {
            return 0;
        }

        long long left_sum = find(root->left, maxP, total);
        long long right_sum = find(root->right, maxP, total);
        long long sum1 = root->val + left_sum + right_sum;
        long long sum2 = total - sum1;
        maxP = max(maxP, sum1 * sum2);
        return sum1;

    }

public:
    int maxProduct(TreeNode* root) {
        if(!root) {
            return 0;
        }
        long long maxP = 0;
        long long total = totalSum(root);
        find(root, maxP, total);
        return maxP%1000000007;


    }
};