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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;
        while(temp) {
            count++;
            temp = temp->next;
        }

        if(count == n) {
            ListNode* deleteNode = head;
            ListNode* newHead = head->next;
            delete deleteNode;
            return newHead;
        }
        int result = count - n;
        temp = head;
        while(temp) {
            result--;
            if(result == 0) {
                break;
            }
            temp = temp->next;
        }
        ListNode* deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;
        return head;
    }
};