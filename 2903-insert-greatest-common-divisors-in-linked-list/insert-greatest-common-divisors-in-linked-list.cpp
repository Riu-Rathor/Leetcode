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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* first = head;
        ListNode* second = head->next;

        while(second) {
            int gcd = __gcd(first->val, second->val);
            ListNode* insertValue = new ListNode(gcd);
            first->next = insertValue;
            first = second;
            insertValue->next = second;
            second = second->next;
        }
        return head;
    }
};