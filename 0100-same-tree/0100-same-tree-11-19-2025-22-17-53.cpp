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
//ek case aisa likho jisme sara condition true ho and recursion v ho
bool solve(TreeNode* p, TreeNode* q){
     if(p==NULL && q== NULL)
            return 1;
    if((p==NULL && q!=NULL) ||(p!=NULL && q==NULL))
        return 0;
    if(p->val !=q->val)
        return 0;

    // if(p->val==q->val && solve(p->left,q->left)&&
    // solve(p->right,q->right)) return 1; //m2:
    return solve(p->left,q->left) && solve(p->right, q->right);    
        
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q); 
    
    }
};