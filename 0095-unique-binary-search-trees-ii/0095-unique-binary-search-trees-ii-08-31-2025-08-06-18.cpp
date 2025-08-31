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
public:  //similar to ques-> all possible full binary tree
    vector<TreeNode*> generateTrees(int n) {
        //b.s.t ->  All values in its left subtree are strictly less than the node's own value. 
            //All values in its right subtree are strictly greater than the node's own value. 
            //  This property applies recursively to all subtrees within the BST.

        //wo unique b.s.t's print kro 
         //1 se leko n tk sbko ek ek krke root manlo b.s.t ka
         //for a i -> left me 1 to i-1 tak ndes hoenge
         // right me i+1 to n nodes
         //left and right ka pairing kro
        return solve(1,n);
    }
    vector<TreeNode *> solve(int i, int n){
        if(i> n)
            return {NULL};
        if(i==n){
           TreeNode * root = new TreeNode(i);
           return {root};
        }

        vector<TreeNode *> ans;

        for(int j=i;j<=n;j++){
            vector<TreeNode *> left_bst = solve(i,j-1);
            vector<TreeNode *> right_bst = solve(j+1,n);

            for(TreeNode * it_l: left_bst){  //pairing kro left and right subtree ka
                for(auto it_r: right_bst){
                    TreeNode * root = new TreeNode(j);
                    root->left = it_l;
                    root->right = it_r;
                    ans.push_back(root);
                }
            }
        }
        return ans;    

    }
};