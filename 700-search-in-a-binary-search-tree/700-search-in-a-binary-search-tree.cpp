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
    
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *r=root;
        while(r!=NULL){
            if(r->val==val){
                return r;
            }
            else if(r->val < val){
                if(r->right){
                    return searchBST(root->right, val);
                }
                else{
                    return NULL;
                }
            }
            else if(r->val > val){
                if(r->left){
                    return searchBST(root->left, val);
                }
                else{
                    return NULL;
                }
            }
        }
        return NULL;
    }
};