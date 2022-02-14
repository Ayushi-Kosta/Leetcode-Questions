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
    int s(int ans, TreeNode* root){
        if(root==NULL){
            return 0;
        }
        else return max(s(ans, root->left), s(ans, root->right))+1;
    }
    int maxDepth(TreeNode* root) {
        int ans=0;
        ans = s(ans, root);
        return ans;
    }
};