/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr = head->next;
        while(curr) {
            ListNode* startNode = curr;
            int sum = 0;
            ListNode* temp = startNode;
            while(temp->val != 0 && temp) {
                sum += temp->val;
                temp = temp->next;
            }

            if(temp->val == 0) {
                startNode->val = sum;
                curr = temp->next;
                startNode->next = temp->next;
            }
        }
        return head->next;
    }
};