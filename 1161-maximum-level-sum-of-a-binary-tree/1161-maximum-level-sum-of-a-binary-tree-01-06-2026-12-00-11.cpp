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
    int maxLevelSum(TreeNode* root) {
        int ans_sum = -1e9;
        int ans_level = 0;
        queue<TreeNode*> q;
        int level = 1;

        q.push(root);

        while(!q.empty()){
            int n = q.size();
            int sum = 0;  //each level pe suru
            while(n--){ //1, 2
                TreeNode * node = q.front();
                q.pop();
                sum+= node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);    
            } 
            if(sum > ans_sum){
                ans_sum = sum;
                ans_level = level;
            }
            level++;
        }
        return ans_level;
    }
};