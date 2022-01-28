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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *head1;
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val > l2->val){
            ListNode* a=new ListNode(l2->val);
            head1=a;
            head=a;
            l2=l2->next;
        }
        else{
            ListNode* a=new ListNode(l1->val);
            head=a;
            head1=a;
            l1=l1->next;
        }
        while(l1 and l2){
            if(l1->val > l2->val){
                ListNode* a=new ListNode(l2->val);
                head1->next=a;
                head1=head1->next;
                l2=l2->next;
            }    
            else{
                ListNode* a=new ListNode(l1->val);
                 head1->next=a;
                 head1=head1->next;
                 l1=l1->next;
            }
        }
        while(l1){
            ListNode* a=new ListNode(l1->val);
                 head1->next=a;
                 head1=head1->next;
                 l1=l1->next;
        }
        while(l2){
            ListNode* a=new ListNode(l2->val);
                head1->next=a;
                head1=head1->next;
                l2=l2->next;
        }
        return head;
    }
};