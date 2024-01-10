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
    // This functionn performs two operations 
    // I - create maping from node to the parent 
    // II - find the node where we have to start
    TreeNode* createParentMaping(TreeNode* root, int target, map<TreeNode*, TreeNode*> &nodeToParent) {
        TreeNode* result = NULL;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if(front->val == target) {
                result = front;
            }
            if(front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }

            if(front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return result;
        
    }

    void infectTree(TreeNode* root, map<TreeNode*, TreeNode*> &nodeToParent, int &time) {
        map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        visited[root] = true;
        while(!q.empty()) {
            bool flag = false;
            int size = q.size();
            for(int i = 0; i<size; i++) {
                // process the neighbouring node
                TreeNode* front = q.front();
                q.pop();
                if(front->left && !visited[front->left]) {
                    q.push(front->left);
                    visited[front->left] = true;
                    flag = true;
                }

                if(front->right && !visited[front->right]) {
                    q.push(front->right);
                    visited[front->right] = true;
                    flag = true;
                }

                if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                    flag = true;
                }

            }
            if(flag) {
                time++;
            }
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        // create time variable to store the result
        int time = 0;
        // Step I - first we create maping of node to its parent
        map<TreeNode*, TreeNode*> nodeToParent;
        // Step II - find the node in the tree from where we have to start
        TreeNode* targetNode = createParentMaping(root, start, nodeToParent);
        // Step III - start infecting the tree        
        infectTree(targetNode, nodeToParent, time);
        return time;
    }
};