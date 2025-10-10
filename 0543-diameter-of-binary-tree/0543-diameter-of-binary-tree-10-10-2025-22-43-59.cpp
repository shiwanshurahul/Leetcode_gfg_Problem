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
    private :
    int solve(TreeNode* root, int & res){
        if(root == nullptr)
            return 0;
        
        int l = solve(root->left,res);
        int r = solve(root->right,res);
        
        int temp = 1 + max(l,r);
        int ans = max(temp,1+l+r);
        res = max(res,ans);
        
        return temp;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = INT_MIN;
        solve(root,res);
        return res -1;
    }
};