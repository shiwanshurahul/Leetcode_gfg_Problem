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
    vector<int> rightSideView(TreeNode* root) {
        //har lvl ka last node ko ans me push_back
        if(root==NULL)
            return {};
        int k =0;
        queue<TreeNode*> q;
        vector<int> ans,temp;

        q.push(root);
        while(!q.empty()){
            int n =q.size();
            k=n;
            while(n--){
                TreeNode* node = q.front();
                temp.push_back(node->val);
                if(node->left!=NULL)
                    q.push(node->left);
                if(node->right!=NULL)
                    q.push(node->right);
                q.pop();        
            }  //aftr this lvl:
            ans.push_back(temp[k-1]);
            temp.clear();
        }
        return ans;
    }
};