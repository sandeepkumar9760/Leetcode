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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before = dummy;

        while(before->next && before->next->next){
            ListNode* left = before->next;
            ListNode* right = left->next;
            ListNode* nxt = right->next;

            left->next = nxt;
            right->next = left;
            before->next = right;
            before = left;
        }
        return dummy->next;
    }
};