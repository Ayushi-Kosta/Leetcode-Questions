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
        if(head==NULL or head->next==NULL) return head;
        ListNode* h=head->next, *prev=NULL;
        while(head!=NULL and head->next!=NULL){
            ListNode* a=head, *b=head->next;
            a->next=b->next;
            b->next=a;
            if(prev!=NULL) prev->next=b;
            prev=a;
            head=a->next;
        }
        return h;
    }
};