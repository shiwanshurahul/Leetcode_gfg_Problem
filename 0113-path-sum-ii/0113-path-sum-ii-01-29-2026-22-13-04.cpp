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
public:   //explore all paths = traditional backtracking
vector<vector<int>> ans;
void solve(TreeNode* root, int targetSum,vector<int>v){
    if(root ==NULL)              //targetSum can be negative toh uspe koi checks ni laga skte
     return;
     v.push_back(root->val);   //take

     if(root->left==NULL && root->right==NULL && targetSum-root->val==0){
        ans.push_back(v);
        return;
     }

     solve(root->left, targetSum-root->val, v);
     solve(root->right, targetSum-root->val, v);

     v.pop_back();    //backtrack

}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //ek case aisa likhenge jisme hm leaf pe hoenge and node->val - target = 0
        vector<int> v;
        solve(root,targetSum,v);
        return ans;
    }
};