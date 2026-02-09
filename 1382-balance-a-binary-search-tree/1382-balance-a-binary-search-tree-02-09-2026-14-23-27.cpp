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
vector<int> v;
void inorder(TreeNode * root){
    if( root ==NULL)
        return;

    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}
TreeNode * build_bst(int s, int e){
    if(s>e)
        return NULL;

    int mid = (s+e)/2;

    TreeNode * node = new TreeNode(v[mid]); 
    node->left = build_bst(s, mid-1);
    node->right = build_bst(mid+1, e);

    return node;
}
    TreeNode* balanceBST(TreeNode* root) {
        //bst me inorder traversl gives nodes in sorted order
        if(root == NULL)
            return NULL;
        inorder(root);  //v = [1,2,3,4]
        
        //ab is sorted order me v hai usse tree banao
        //same as segment Tree
        int n = v.size();
        return build_bst(0,n-1);  //s,e
    }   
};