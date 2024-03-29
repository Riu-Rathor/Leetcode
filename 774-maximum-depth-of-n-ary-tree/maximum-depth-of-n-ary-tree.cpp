/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(!root) {
            return 0;
        }
        
        int ans = 0;
        for(auto it : root->children) {
            ans = max(ans, maxDepth(it)); 
        }
        return ans + 1;
        // int depth = 0;
        // queue<Node*> q;
        // q.push(root);
        // while(!q.empty()) {
        //     int size = q.size();
        //     depth++;
        //     for(int i=0; i<size; i++) {
        //         Node* front = q.front();
        //         q.pop();
        //         for(auto it : front->children) {
        //             q.push(it);
        //         } 
        //     }
        // }
        // return depth;
    }
};