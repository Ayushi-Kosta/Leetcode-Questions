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
    void helper(TreeNode* root, int &count, int maxi){
        if(maxi<=root->val){
            count++;
            // cout<<root->val<<" ";
        }
        maxi=max(root->val, maxi);
        if(root->left) helper(root->left, count, maxi);
        if(root->right) helper(root->right, count, maxi);
        
    }
    int goodNodes(TreeNode* root) {
        // maintain a max value and 
        // if curr is smaller than max, means its not good 
        // if curr is greater than max, means its good 
        int count=0;
        helper(root, count, INT_MIN);
        return count;
    }
};