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
    void r(TreeNode *root, vector<int> &s){
        if(root==NULL) return ;
        s.push_back(root->val);
        r(root->left, s);
        r(root->right, s);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> s;
        r(root, s);
        sort(s.begin(), s.end());
        int n = s.size(), l=0, r=n-1;
        while(l<r){
            if(s[l]+s[r] > k){
                r--;
            }
            else if(s[l]+s[r] < k){
                l++;
            }
            else{
                return 1;
            }
        }
        return 0;
    }
};