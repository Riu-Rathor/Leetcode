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

    bool findLength(ListNode* head, int k) {
        int count = 0;
        while(head != NULL) {
            head = head->next;
            count++;
        }    

        if(count < k) {
            return false;
        } 
        return true;
    }


public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) {
            return NULL;
        }


        if(findLength(head, k) == false) {
            return head;
        }

        // reverse by the iterative method
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* curr = head;
        int count = 0;
        
        while(curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != NULL) {
            head->next = reverseKGroup(curr, k);
        }

        return prev;
    }
};