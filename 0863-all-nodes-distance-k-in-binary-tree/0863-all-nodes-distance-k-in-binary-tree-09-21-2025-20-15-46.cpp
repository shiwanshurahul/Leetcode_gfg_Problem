/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*, TreeNode *> par;  //son, par
void find_parent(TreeNode* root){
    if(!root)
        return;

    if(root->left){
        par[root->left] = root; 
        find_parent(root->left);
    }    
    if(root->right){
        par[root->right] = root;
        find_parent(root->right);
    }   
}
 void markparents(TreeNode* root, TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                par[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right] = node;
                q.push(node->right);
            }
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //k edges dur wala node from target
        //bfs kro from target -> level order traversal
        //but upar kaise?
        //ek edge bana do tm to represent parent of each node = isse traverse kr skte
        //mp me store parent
        
        find_parent(root);   //-> dfs jaisa
        // markparents(root, target);  //-> bfs 

        queue<TreeNode*> q;
        unordered_set<int> vis;
        vector<int> ans;

        q.push(target);
        vis.insert(target->val);
        int level =0;

        while(!q.empty()){
            int size = q.size();
            if(level==k)
                break;
            while(size--){
                TreeNode * node = q.front();
                q.pop();
                if(node->left && vis.find(node->left->val)==vis.end()){
                    q.push(node->left);
                    vis.insert(node->left->val);
                }

                if(node->right && vis.find(node->right->val)==vis.end()){
                    q.push(node->right);
                    vis.insert(node->right->val);
                }

                if(par.find(node) !=par.end()  && vis.find(par[node]->val) ==vis.end()){  //parent pe check
                    q.push(par[node]);
                    vis.insert(par[node]->val);
                }
            }    
            level++;
        }
        //k level ke sb elem q me hai
        while(!q.empty()){
            TreeNode * temp = q.front();
            ans.push_back(temp->val); q.pop();
        }
        return ans;

    }
};