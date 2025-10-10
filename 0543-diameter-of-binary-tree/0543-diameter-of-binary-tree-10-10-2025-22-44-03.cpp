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
int height(TreeNode *root){
    if(root==NULL)
        return 0;
    int a = height(root->left);
    int b = height(root->right);
    return  1 + max(a,b); //1 for root
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
            return 0;
        int x = diameterOfBinaryTree(root->left); //left se 
        int y = diameterOfBinaryTree(root->right);  //right se

        int z = height(root->left) + height(root->right); //height of binary tree
        return max(x,max(y,z));

    }
};