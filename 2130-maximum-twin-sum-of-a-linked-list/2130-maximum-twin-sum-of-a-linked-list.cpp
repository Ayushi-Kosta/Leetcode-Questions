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
    int pairSum(ListNode* head) {
        ListNode *slow=head, *fast=head, *temp=head;
        stack<int> s;
        while( fast!=NULL and fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=head;
        int ans=INT_MIN;
        while(slow!=temp){
            s.push(temp->val);
            temp=temp->next;
        }
        while(slow!=NULL){
            int a=s.top();
            s.pop();
            ans=max(ans, (slow->val+a));
            slow=slow->next;
        }
        return ans;
    }
};