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
    bool isValidBST(TreeNode* root, long long  left = -1e11, long long right = 1e11) {
        if(root == NULL) return true;
        if(root->val <= left or root->val >= right) return false;
        return isValidBST(root->right, root->val, right) and isValidBST(root->left, left, root->val);
    }
    
    
    
    // bool isValidBST(TreeNode* root) {
    //     if(root==NULL){
    //         return 1;
    //     }
    //     if((root->left==NULL and root->right!=NULL) or (root->right==NULL and root->left!=NULL)){
    //         return 0;
    //     }
    //     if((root->left==NULL and root->right==NULL)){
    //         return 1;
    //     }
    //     return ((root->left==root->right and root->left==NULL) or ((root->val>root->left->val) and  (root-   >val<root->right->val))) and (isValidBST(root->left) and isValidBST(root->right));
    // }
};