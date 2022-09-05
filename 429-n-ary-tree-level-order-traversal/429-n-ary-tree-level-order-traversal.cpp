/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node *> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            
            for(int i=0; i<n; i++){
                Node * curr = q.front();
                if(!curr) return ans;
                q.pop();
                v.push_back(curr->val);
                for(auto &x : curr->children){
                    if(x){
                        q.push(x);
                    }
                }
               
            }
            ans.push_back(v);
        }
        return ans;
    }
};