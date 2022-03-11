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
    ListNode* rotateRight(ListNode* head, int k){
        if(!head or k==0) return head;
        int n = 0;
        ListNode* a = head;
        while(a!=NULL){
            a=a->next;
            n++;
        }
        a=head;
        if(k==n or n==0) return head;
        k=k%n;
        int q = n-k-1;
        //cout<<"k "<<k<<" ";
        if(k==0) return head;
        while(q){
            q--;
            a=a->next;
        }
        //cout<<"-"<<a->val<<"-";
        ListNode *w = a->next, *h = w;
        a->next=NULL;
        while(w and w->next!=NULL){
            w=w->next;  
        }
        if(w) w->next = head;
        //cout<<n<<" ";
        return h;
    }
};