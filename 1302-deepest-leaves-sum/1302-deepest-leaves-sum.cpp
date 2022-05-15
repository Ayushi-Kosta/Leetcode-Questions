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
    vector<pair<int, int>> v; //root, height
    static bool myfun(pair<int, int> &a, pair<int, int> &b){
        return (a.second>b.second);
    }
    void s(TreeNode* root, int height){
        if(root==NULL){
            return;
        }
        if(root->left==NULL and root->right==NULL){
            v.push_back({root->val, height});
        }
        if(root->left){
            s(root->left, height+1);
        }
        if(root->right){
            s(root->right, height+1);
        }
        
    }
    int deepestLeavesSum(TreeNode* root) {
        s(root, 1);
        sort(v.begin(), v.end(), myfun);
        int i = v[0].second;
        int j=0, sum=0;
        // for(auto &x: v){
        //     cout<<x.first<<" "<<x.second<<" \ ";
        // }
        while(j<v.size() and v[j].second==i){
            sum+=(v[j].first);
            j++;
        }
        return sum;
    }
};