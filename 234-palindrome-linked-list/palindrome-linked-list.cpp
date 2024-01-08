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
    ListNode* reverse(ListNode* head) {

        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && slow) {
            slow =  slow->next;
            fast = fast->next;
            if(fast != NULL) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        ListNode* last = reverse(mid);
        ListNode* curr = head;
        while(last != NULL) {
            if(last->val != curr->val) {
                return false;
            }
            last = last->next;
            curr = curr->next;
        }
        return true;


    }
};