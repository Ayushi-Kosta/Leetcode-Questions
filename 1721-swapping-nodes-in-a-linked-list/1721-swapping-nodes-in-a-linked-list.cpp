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
    ListNode* swapNodes(ListNode* head, int k) {
        int i=1, n=0;
        ListNode* h1 = head, *h2=head, *h3=head;
        while(h3!=NULL){
            n++;
            h3=h3->next;
        }
        h3=head;
        while(h3!=NULL){
            if(i==k){
                h1=h3;
            }
            if(i==(n-k+1)){
                h2=h3;
            }
            h3=h3->next;
            i++;
        }
        int a = h1->val;
        h1->val=h2->val;
        h2->val=a;
        return head;
    }
};