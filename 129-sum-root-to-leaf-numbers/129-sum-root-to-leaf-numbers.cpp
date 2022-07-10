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
// class Solution {
// public:
//     int s(TreeNode* root, int cur, sum){
//         int cur = cur*10 + root-val;
//         if(root==NULL) return curr;
//         return s(root->left)
//     }
//     int sumNumbers(TreeNode* root) {
//         int cur = 0;
//         if(root==NULL) return 0;
//         return s(root, 0);
//     }
// };



























class Solution {
public:
    int total=0;
    void s(TreeNode* root, int sum){
        if(root==NULL) return;
        int our_sum=(sum*10)+(root->val);
        if(!root->left and !root->right){
            total+=(our_sum);
            return;
        }
        s(root->left, our_sum);
        s(root->right, our_sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum=0;
        s(root, sum);
        return total;
        
    }
};