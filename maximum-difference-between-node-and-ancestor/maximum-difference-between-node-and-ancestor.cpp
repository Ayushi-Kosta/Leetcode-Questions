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
//     int res=0;
//     int s(TreeNode* root, int &maxi, int &mini){
//         if(root==NULL){
//             return 0;
//         }
//         if(root) maxi=root->val;
//         if(mini<maxi){
//             res=max(res, maxi-mini);
//             mini=min(root->val, mini);
//         }

//         int a1=s(root->left, maxi, mini);
//         int a2=s(root->right, maxi, mini);
//     }
    // void s(TreeNode* root, int &maxi, int &mini){
    //     if(root and root->val < mini){
    //         mini=root->val;
    //     }
    //     if(root and root->val > maxi){
    //         maxi=root->val;
    //     }
    //     res=max(res, maxi-mini);
    //     if(root->left) s(root->left, maxi, mini);
    //     if(root->right) s(root->right, maxi, mini);
    // }
    int s(TreeNode* root, int maxi=INT_MIN, int mini=INT_MAX){
        if(root==NULL){
            return maxi-mini;
        }
        maxi=max(root->val, maxi); mini=min(root->val, mini);
        int a1=s(root->left, maxi, mini), a2=s(root->right, maxi, mini);
        return max(a1, a2);
    }
    int maxAncestorDiff(TreeNode* root) {        
        if(root==NULL){
            return 0;
        }
        int maxi=INT_MIN, mini=INT_MAX;
        int ans=s(root, maxi, mini);
        return ans;
        
    }
    
};