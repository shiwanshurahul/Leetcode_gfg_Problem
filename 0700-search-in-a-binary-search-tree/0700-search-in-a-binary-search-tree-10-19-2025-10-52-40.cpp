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
//b.s.t me insert hmesa leaf pe hoga -> pehla node ya child position pe
TreeNode *solve(TreeNode* &root, int &val){
    if(root==NULL)
        return NULL;
    if(root->val==val)  //same pattern repeated in b.s.t
        return root;
    if(root->val >val)  //go to left subtree
        return solve(root->left,val);
    else if(root->val <val)
        return solve(root->right,val);
    return NULL;

}
    TreeNode* searchBST(TreeNode* root, int val) {
        //bst -> for each node -> left subtree <root < right subtree
       return solve(root,val);

    }
};