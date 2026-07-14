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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode* first = head;
        ListNode* prev = head;
        ListNode* temp = head;
        int size = 1;
        ListNode* check = head;
        while(check->next!=nullptr){
            size++;
            check = check->next;
        }
        k = k%size;
        while(k--){
            while(temp->next!=nullptr){
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            temp->next = first;
            first = temp;
        }
        return temp;
    }
};