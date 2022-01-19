/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head, *fast=head;
        while(fast!=NULL and fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                break;
            }
        }
        if(!(fast and fast->next)){
            return NULL;
        }
        while(slow!=head){
            slow=slow->next;
            head=head->next;
        }
        return slow;
    }
};