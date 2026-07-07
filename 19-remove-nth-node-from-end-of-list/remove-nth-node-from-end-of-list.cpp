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
        if(!head) return head;
        ListNode* temp = head;
        int size = 0;
        while(temp!=nullptr){
            temp=temp->next;
            size++;
        }
        int delete_node = size-n;
        if(delete_node<=0) return head->next;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* left = head;
        for(int i=0; i<delete_node; i++){
            prev = left;
            left = left->next;
        }
        ListNode* nxt = left->next;
        prev->next = nxt;
        return head;
    }
};