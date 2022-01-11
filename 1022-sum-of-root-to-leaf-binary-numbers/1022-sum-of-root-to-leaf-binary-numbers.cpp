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
    int btod(string s){
        int n=s.size(), ans=0;
        int c=1, i=n-1;
        while(i>=0){
            if(s[i]=='1'){
                ans += c;
            }
            c*=2;
            i--;
        }
        return ans;
    }
    vector<string> ans;
    void s(TreeNode* root, string v){
        if(root!=NULL){
            v+=(root->val+'0');
        }
        if(root->left==NULL and root->right==NULL){
            ans.push_back(v);
            return ;
        }
        if(root->left){
            s(root->left, v);
        }
        if(root->right){
            s(root->right, v);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        string v;
        int z=0;
        s(root, v);
        for(int i=0; i<ans.size(); i++){
            z+=(btod(ans[i]));
            cout<<ans[i]<<" ";
        }
        // string a="11";
        // int b= btod(a);
        // cout<<b;
        return z;
    }
};