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
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *r1 = l1, *r2 = l2;
        int carry =0;
        ListNode * h = NULL, *head=new ListNode(0);
        
        while(r1!=NULL or r2!=NULL or carry){
            int c = (r1?r1->val:0)+(r2?r2->val:0) + carry;
            carry=c/10;
            ListNode* a = new ListNode(c%10);
            if(h==NULL){
                h=a;
                head=h;
            }
            else{
                h->next=a;
                h=h->next;
            } 
            
            r1=r1?r1->next: r1;
            r2=r2?r2->next: r2;
        }
        return head;
    }
};