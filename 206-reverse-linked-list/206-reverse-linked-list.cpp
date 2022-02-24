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
        if(head==NULL){
            return NULL;
        }
        ListNode * a=head;       
        ListNode *z=head, *pre=NULL;
        while(a!=NULL){
            a=z->next;
            z->next=pre;
            pre=z;
            z=a;
        }
        return pre;
    }
};