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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root==NULL){
            return v;
        }
        q.push(root);
        while(!q.empty()){
            int n_q = q.size();
            vector<int> z;
            for(int i=0; i<n_q; i++){
                TreeNode* a = q.front();
                q.pop();
                z.push_back(a->val);
                if(a->left!=NULL) q.push(a->left);
                if(a->right!=NULL) q.push(a->right);
            }
            v.push_back(z);
        }
        return v;
    }
};