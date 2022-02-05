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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> v;
        ListNode* head1=NULL;
        if(lists.size()==0){
            return head1;
        }
        int n=lists.size();
        for(int i=0; i<n; i++){
            ListNode *temp=lists[i];
                while(temp!=NULL){
                    v.push_back(temp->val);
                    temp=temp->next;
            }
        }
        sort(v.begin(), v.end());
        
        int n_v=v.size();
        if(n_v==0){
            return 0;
        }
        head1 =new ListNode(v[0]);
        ListNode *head2=head1;
        for(int i=1; i<n_v; i++){
            ListNode* a=new ListNode(v[i]);
            head2->next=a;
            head2=a;
        }
        return head1;
    }
};