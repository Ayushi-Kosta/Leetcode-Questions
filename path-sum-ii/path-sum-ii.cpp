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
    vector<vector<int>>v;
    void s(TreeNode* root, int ts, int sum, vector<int> a){
        
        if(root==NULL){
            return ;
        }
        sum+=root->val;
        a.push_back(root->val);
        if(root->left==NULL and root->right==NULL){
            if(ts==sum){
                v.push_back(a);
            }
        }
        if(root->left) s(root->left, ts, sum, a);
        if(root->right) s(root->right, ts, sum, a);
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int ts) {
        int sum=0;
        vector<int> a;
        s(root, ts, sum, a);
        return v;
    }
};