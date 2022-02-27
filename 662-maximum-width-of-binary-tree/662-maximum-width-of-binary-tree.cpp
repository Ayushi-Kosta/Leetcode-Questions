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
    void levelorder_order_trav(TreeNode* root, long long &ans) {
        TreeNode *a = root;
        if(a==NULL){
            return ;
        }
        queue<pair<TreeNode*, int>> q;
        q.push({a, 0});
        while(!q.empty()){
            int n = q.size();
            //cout<<n<<" ";
            int count=0;
            long long int lef = q.front().second, id=0;
            for(int i=0; i<n; i++){
                TreeNode * w = q.front().first;
                id = q.front().second;
                q.pop();
                if(w->left){
                    q.push({w->left, 2*id+1});
                }
                
                if(w->right){
                    q.push({w->right, 2*id+2});
                }
                
            }
            ans=max(ans, (id-lef+1));
        }
    }
    int widthOfBinaryTree(TreeNode* root) {
        long long ans=0;
        levelorder_order_trav(root, ans);
        return ans;
    }
};