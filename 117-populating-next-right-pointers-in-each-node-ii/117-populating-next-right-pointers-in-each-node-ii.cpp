/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // bfs
        Node* Root=root;
        queue<Node*> q;
        q.push(root);
        if(root==NULL){
            return root;  
        } 
        while(!q.empty()){
            int n = q.size();
            Node* a;
            for(int i=0; i<n; i++){
                a = q.front();
                q.pop();
                if(i!=n-1){
                    a->next=q.front();
                }
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
            a->next=NULL;
        }
        return Root;
    }
};