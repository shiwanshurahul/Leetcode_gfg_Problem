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
    bool isCompleteTree(TreeNode* root) {
        //as left as possible
        //check ki null ke bad koi node na aaye
        //q me push null als
        queue<TreeNode*> q;
        q.push(root);
        int is_null = 0;  //check ki abtak null aaya

        while(!q.empty()){
            int n = q.size();
            TreeNode * node = q.front();
            q.pop();
            if(node == NULL){
                is_null = 1;
            }    
            else{
                if(is_null)
                    return false;  //not a complete binary tree
                q.push(node->left);
                q.push(node->right);
            }    
        }
        return true;
    }
};