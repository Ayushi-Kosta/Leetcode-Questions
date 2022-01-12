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
    TreeNode* insertIntoBST(TreeNode* root, int x) {
        if(root==NULL){
            //TreeNode* a;
            //a->val=x;
            return new TreeNode(x);
        }
        else if(root->val < x){
            root->right = insertIntoBST(root->right, x);
        }
        else if(root->val > x){
            root->left = insertIntoBST(root->left, x);
        }
        return root;
    }
};