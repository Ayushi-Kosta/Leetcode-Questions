/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* a = root, *prev=root;
        while(a!=NULL){
            if(a->val==p->val || a->val==q->val){
                return a;
            }
            else if(a->val > p->val and a->val > q->val){
                prev=a;
                a=a->left;
            }
            else if((a->val > p->val and a->val < q->val) or (a->val < p->val and a->val > q->val)){
                return a;
            }
            else if(a->val < p->val and a->val < q->val){
                a=a->right;
                prev=a;
            }
            
        }
        return prev;
    }
};