/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* prev = NULL, *first=NULL, *second=NULL;
    void inor(TreeNode* root){
        if(root==NULL){
            return ;
        }
        inor(root->left);
        if(prev!=NULL and first==NULL){
            if(prev->val>root->val){
                first=prev;
            }
        }
        if(prev!=NULL and prev->val>root->val){
            second=root;
        } 
        prev=root;
        inor(root->right);
    }
    void recoverTree(TreeNode* root) {
        inor(root);
        int s=0;
        if(first!=NULL) s = first->val;
        if(first!=NULL and second!=NULL) first->val = second->val;
        if(second!=NULL) second->val = s;        
    }
};