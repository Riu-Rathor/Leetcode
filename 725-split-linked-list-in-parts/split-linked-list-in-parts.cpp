/*
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
    int lengthOfLinkedList(ListNode* head){
        int ans = 0;
        ListNode* curr = head;
        while(curr) {
            ans++;
            curr = curr->next;
        }
        return ans;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        if(!head) {
            for(int i=0; i<k; i++) {
                ans.push_back(NULL);
            }
            return ans;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        int length = lengthOfLinkedList(head);
        int noOfNodes = length / k;
        int remainder = length % k;
        
        for(int i=0; i<k; i++) {
            int split = noOfNodes;
            if(curr) {
                ans.push_back(curr);
            }
            else {
                ans.push_back(NULL);
            }
            while(curr && split) {
                prev = curr;
                curr = curr->next;
                split--;
            }

            if(curr && remainder) {
                prev = curr;
                curr = curr->next;
                remainder--;
            }

            prev->next = NULL;
        }
        return ans;
    }
};