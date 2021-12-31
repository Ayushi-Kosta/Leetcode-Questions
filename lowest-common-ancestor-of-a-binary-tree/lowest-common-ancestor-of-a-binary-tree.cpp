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
        int n1=p->val, n2=q->val;
        if(root==NULL){
            return root;
        }
        if(root->val==n1 or root->val==n2){
            return root;
        }
        TreeNode* lca1=lowestCommonAncestor(root->left, p, q);
        TreeNode* lca2=lowestCommonAncestor(root->right, p, q);
        if(lca1!=NULL and lca2!=NULL){
            return root;
        }
        else if(lca1!=NULL){
            return lca1;
        }
        else return lca2;
    }
};