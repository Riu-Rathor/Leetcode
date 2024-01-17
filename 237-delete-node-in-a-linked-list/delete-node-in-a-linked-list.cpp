/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        int data = node->next->val;
        ListNode* currNode = node;
        ListNode* nextNode = node->next;
        ListNode* nextToNextNode = node->next->next;
        currNode->next = nextToNextNode;
        nextNode->next = NULL;
        delete nextNode;
        currNode->val = data;        
    }
};