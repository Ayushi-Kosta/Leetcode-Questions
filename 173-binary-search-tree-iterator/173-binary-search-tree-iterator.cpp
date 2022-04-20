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
// class BSTIterator {
// public:
//     TreeNode* r = NULL;
    
//     BSTIterator(TreeNode* root) {
        
//     }
    
//     int next() {
//         int a = r->val;
//         r=r->right;
//         return a;
//     }
    
//     bool hasNext() {
        
//     }

class BSTIterator {
    
    TreeNode* head ;
    
    void convert(TreeNode* root , TreeNode* &prev , TreeNode* &next)
    {
        if(root == NULL) return ;
        convert(root->left , prev , next) ;
        
        if(next == NULL){
            next = root ;
        }
        
        if(prev!= NULL)
        {
            prev->right = root ;
        }
            root->left = NULL ;
            prev = root ;
        
        convert(root->right, prev , next) ;
    }
    
public:
    BSTIterator(TreeNode* root) {
        head = NULL ;
        head = new TreeNode(0) ;
        
        TreeNode* prev = NULL ;
        TreeNode* &next = head->right ;
        convert(root , prev , next) ;

    }
    
    int next() {
        head = head->right ;
        return head->val ;
    }
    
    bool hasNext() {
        return head->right != NULL ; 
     }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */