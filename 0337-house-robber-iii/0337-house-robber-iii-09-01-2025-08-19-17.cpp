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
unordered_map<TreeNode *,int> mp[2];
int solve(TreeNode * root, int flag){
    if(root==NULL)
        return 0;

    if(mp[flag].find(root) !=mp[flag].end())
        return mp[flag][root];

    int steal = 0;
    int skip = 0;

    if(flag == 1){  //churao
        steal = root->val + solve(root->left, 0 ) + solve(root->right, 0); //can't steal at next level
        skip = solve(root->left, 1) + solve(root->right, 1);  //dp 
    }
    else {  //pichle level pe steal kiye
        skip = solve(root->left, 1) + solve(root->right, 1);
    }

    return mp[flag][root] = max(steal, skip);    
}
    int rob(TreeNode* root) {
        //buy, sell wala concept -> har node ke respect me likho
        //memoize tree me map se krte
        // here, 2d dp 
        return solve(root,1);  //root se chura skte
    }
};