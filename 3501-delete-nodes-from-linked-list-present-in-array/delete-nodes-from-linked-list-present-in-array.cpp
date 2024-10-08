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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;
        for(int i=0; i<nums.size(); i++) {
            st.insert(nums[i]);
        }
        if(!head) {
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr) {
            if(st.find(curr->val) != st.end()) {
                if(curr == head) {
                    curr = curr->next;
                    head = curr;
                }
                else {
                    prev->next = curr->next;
                    curr = curr->next;
                }
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};