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
    int number=0;
    void helper(TreeNode *root, long cur){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL and root->right==NULL){
            cur=cur*10+root->val;
            number+=cur;    
            // cout<<cur<<" ";
        } 
        
        cur=cur*10+root->val;  
        
        if(root->left) helper(root->left, cur);
        if(root->right) helper(root->right, cur);        
        
        
    }
    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return number;
    }
};