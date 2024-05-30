/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) {
            return NULL;
        }

        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            Node* prevNode = NULL;
            while(n--) {
                Node* frontNode = q.front();
                q.pop();
                if(prevNode) {
                    prevNode->next = frontNode;
                }

                if(frontNode->left) {
                    q.push(frontNode->left);
                }

                if(frontNode->right) {
                    q.push(frontNode->right);
                }

                prevNode = frontNode;
            }
        }
        return root;
    }
};