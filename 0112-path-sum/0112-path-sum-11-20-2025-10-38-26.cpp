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
 //tree me koi ek case likh do jisme true wale ho and then recursive calls 
class Solution {
public:
//ek case aisa likho jisme true ho
bool solve(TreeNode* root, int targetSum){
    if(root==NULL)
        return 0;
    else if(root->left==NULL  && root->right==NULL && targetSum- root->val==0) //kisi leaf pe hai
        return 1;
        
    return solve(root->left,targetSum-root->val) ||
       solve(root->right,targetSum- root->val);   //dono parts pe call
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum);
    }
};