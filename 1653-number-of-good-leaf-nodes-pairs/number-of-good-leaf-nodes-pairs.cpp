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

    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>> &adj, unordered_set<TreeNode*> &st) {
        if(!root) {
            return;
        }

        if(!root->left && !root->right) {
            st.insert(root);
        }

        if(prev) {
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }

        makeGraph(root->left, root, adj, st);
        makeGraph(root->right, root, adj, st);
    }
public:
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj; //Graph
        unordered_set<TreeNode*> st; // leaf nodes
        makeGraph(root, NULL, adj, st);

        int count = 0;
        for(auto &leaf : st) {
            // BFS
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(leaf);
            visited.insert(leaf);

            for(int i=0; i<=distance; i++) {
                int size = q.size();
                while(size--) {
                    TreeNode* curr = q.front();
                    q.pop();
                    if(curr != leaf && st.find(curr) != st.end()) {
                        count++;
                    }

                    for(auto &neighbour : adj[curr]) {
                        if(!visited.count(neighbour)) {
                            q.push(neighbour);
                            visited.insert(neighbour);
                        }
                    }
                }
            }
        }
        return count / 2;
    }
};