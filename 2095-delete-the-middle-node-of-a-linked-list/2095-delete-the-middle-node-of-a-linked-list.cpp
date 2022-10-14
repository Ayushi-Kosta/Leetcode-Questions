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
    ListNode* deleteMiddle(ListNode* head) {
        // t->nxt->nxt t->nxt del, t->nxt prev del
        ListNode* slow = head, *fast = head, *prev = NULL;
        if(head->next==NULL){
            return NULL;
        }
        while(fast->next != NULL and fast->next->next != NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(!fast->next){
            prev->next=slow->next;
        }
        else{
            slow->next = slow->next->next;
        }
        return head;
        
    }
};