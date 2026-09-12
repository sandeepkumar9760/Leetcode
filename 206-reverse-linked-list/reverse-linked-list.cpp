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
    ListNode* reverseList(ListNode* head) {
        ListNode* crr = head;
        ListNode* prev = nullptr;
        while(crr){
            ListNode* next = crr->next;
            crr->next = prev;
            prev = crr;
            crr = next;
        }
        return prev;
    }
};