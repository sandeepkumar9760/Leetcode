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
    struct cmp{
        bool operator()(ListNode* a , ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size==0) return nullptr;
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(int i=0;i<size;i++){
            if(lists[i]!=nullptr){
                pq.push(lists[i]);
            }
        }
        ListNode* dummy = new ListNode(0);
        ListNode* copy = dummy;
        while(!pq.empty()){
            ListNode* crr = pq.top();
            pq.pop();
            copy->next = crr;
            copy = crr;
            if(crr->next){
                pq.push(crr->next);
            }
        }
        return dummy->next;
    }
};