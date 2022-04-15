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
    TreeNode* s(TreeNode* root, int low, int high) {
        if(root==NULL){
            return NULL;
        }
        if(root->val>=low and root->val<=high){
            root->right=s(root->right, low, high);
            root->left=s(root->left, low, high);
        }
        else if(root->val<low){
            root=s(root->right, low, high);
        }
        else if(root->val>high){
            root=s(root->left, low, high);
        }
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return s(root, low, high);
    }
};