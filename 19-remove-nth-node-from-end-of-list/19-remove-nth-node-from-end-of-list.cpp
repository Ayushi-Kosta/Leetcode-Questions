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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *a = head;
        int count=0;
        while(a!=NULL){
            a=a->next;
            count++;
        }
        if(count<=1){
            return NULL;
        }
        int rem = count-n; //remove (count-n+1) th node
        int i=1;
        a=head;
        if(rem==0){
            return head->next;
        }
        while(i<rem){
            a=a->next;
            i++;
        }
        ListNode *temp=a->next->next;
        a->next=temp;
        return head;
    }
};