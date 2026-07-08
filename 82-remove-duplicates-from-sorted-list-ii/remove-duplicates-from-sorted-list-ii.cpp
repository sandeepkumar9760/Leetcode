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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* crr = head;
        while(crr!=nullptr){
            if(crr->next!=nullptr && crr->val == crr->next->val){
                while(crr->next!=nullptr && crr->val == crr->next->val){
                    crr = crr->next;
                }
                prev->next = crr->next;
                crr = crr->next;

            }else{
                prev = crr;
                crr=crr->next;
            }
            
        }
        return dummy->next;
    }
};