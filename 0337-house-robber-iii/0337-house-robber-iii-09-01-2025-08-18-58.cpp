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
unordered_map<TreeNode*, int> dp[2]; //can;t take vecotr or arr bcz nodes can be duplicate
int solve(TreeNode * root, bool parent_robbed){
    if(root ==NULL)
        return 0;

    if(dp[parent_robbed].find(root) != dp[parent_robbed].end())
        return dp[parent_robbed][root];

   int skip =0; 
   int rob = 0;    
   if(parent_robbed)  {  //har node ki kahani
        skip = solve(root->left, 0) + solve(root->right, 0);
   }
   else {
        rob = root->val + solve(root->left, 1) + solve(root->right, 1);
        skip = solve(root->left, 0) + solve(root->right, 0);
   }
   
    return dp[parent_robbed][root] = max(rob, skip); 
}
//har node ke respect me likh do
    int rob(TreeNode* root) {
        if(root ==NULL)
            return 0;
        return solve(root, false);  //iska parent rob ni hua= can rob root
    }
};