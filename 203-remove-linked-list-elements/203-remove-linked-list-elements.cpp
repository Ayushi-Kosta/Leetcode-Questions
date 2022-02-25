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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* a = head, *prev=NULL;
        bool t=1;
        while(a!=NULL){
            if(a->val==val){
                a=a->next;
            }
            else{
                
                if(prev!=NULL) prev->next=a;
                prev=a;
                if(t){
                    head=prev;
                    t=0;
                } 
                a=a->next;
            }
        }
        if(prev!=NULL) prev->next=a;
        if(prev==NULL) return NULL;
        return head;
    }
};