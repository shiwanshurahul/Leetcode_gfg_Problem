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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //bst-> for each node -> left<root<right isliye inorder gives in sorted order -> left, root, right
        //insert hmesa leaf pe hoga chahe pehla node ya child position pe

     if(root==NULL)   //sahi jagah pe ho = create node and return
        return new TreeNode(val);
    // if root is null append val to that position and return that new node fir wo apne ap jahan se recusrive call aaya tha krte original root ko return krega
     if(root->val> val)  //goto left
        root->left = insertIntoBST(root->left,val);
     else if(root->val < val)
        root->right = insertIntoBST(root->right,val);
     return root; 
    }
};