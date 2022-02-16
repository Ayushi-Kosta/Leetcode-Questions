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
    void r(TreeNode* root, vector<int> &v){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            r(root->left, v);
        }
        if(root->right!=NULL){
            r(root->right, v);
        }
        if(root->left==NULL and root->right==NULL){
            v.push_back(root->val);
        }
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        r(root1, a);
        r(root2, b);
        return a==b;
    }
};