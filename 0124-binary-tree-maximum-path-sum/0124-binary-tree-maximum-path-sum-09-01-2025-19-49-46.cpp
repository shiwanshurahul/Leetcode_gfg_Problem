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
int ans = -1e9;
int solve(TreeNode * root){
    if(root==NULL)
        return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    int sbse_aa_rha = l+r+ root->val;
    int l_r_mese_ek_accha = max(l,r) + root->val;
    int only_root_accha = root->val;

    ans = max({sbse_aa_rha, l_r_mese_ek_accha, only_root_accha, ans});

    return max(l_r_mese_ek_accha, only_root_accha);
}
    int maxPathSum(TreeNode* root) {
        //max path sum -> kisi v node se start and kisi pe end
       
        solve(root);
        return ans;
    }//100
};  // -2  -3   -> o/p-> max(100,-2,-3,98,97, 95) = 100

//3 cases
// l+r+root->val   -> good sum from l and r
 //max(l,r) + root->val -> dono me jo max ho
 //root->val     -> l,r are negative toh bas currv
// we must consider any path, not just from root to leaf. This includes paths that may start and end at any node,
// as long as the path moves only downward (parent → child).
// We need to evaluate the best path that includes each node as the highest point 
//(peak) of the path. This means computing the sum of the node + max path on left + max path on right.

