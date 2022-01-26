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
    void s(TreeNode* r, vector<int> &v){
        if(r==NULL){
            return;
        }
        if(r->left!=NULL){
            s(r->left, v);
        }
        v.push_back(r->val);
        if(r->right!=NULL){
            s(r->right, v);
        }
        
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v, w, ans;
        s(root1, v);
        s(root2, w);
        int i=0, j=0, nv=v.size(), nw=w.size();
        while(i<nv and j<nw){
            if(v[i]>w[j]){
                ans.push_back(w[j++]);
            }
            else{
                ans.push_back(v[i++]);
            }
        }
        while(i<nv){
            ans.push_back(v[i++]);
        }
        while(j<nw){
            ans.push_back(w[j++]);
        }
        
        return ans;
        
    }
};