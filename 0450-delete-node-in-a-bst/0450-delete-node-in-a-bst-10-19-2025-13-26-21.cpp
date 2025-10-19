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
int maxi = -1e9;
//b.s.t me inorder is in sorted way (left,node->val,right)
//b.s.t me insert hmesa leaf pe hoga -> pehla node ya child position pe
int get_max(TreeNode *root){
    while(root->right !=NULL){
        root = root->right;
    }
    return root->val;
}
TreeNode* solve (TreeNode * root, int key){
    if(root==NULL)
        return root;

    if(root->val ==key){
        //root has 0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;  //NULL lagado
        }
        //root has 1 child  -> can be left/right child
        if(root->left && !root->right){  //left child hai
            TreeNode * temp = root->left;
            delete(root);
            return temp;  //child lagado/insert
        }
        if(!root->left && root->right){  //right child hai
            TreeNode * temp = root->right;
            delete(root);
            return temp;
        }
        //root has 2 child
        if(root->left !=NULL && root->right !=NULL){
            int maxi = get_max(root->left);  //ya min from right subtree nikal
            root->val = maxi;
            root->left = solve(root->left, maxi);  //delete wo max val wala node
            return root;
        }
    }
    else if(root->val > key){  //goto left subtree
        root->left = solve(root->left,key);
        return root;
    }
    else{   //right subtree me jao
        root->right = solve(root->right, key);
        return root;
    }

    return NULL; // if key ni hai tree me     
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        //jis node ko delete krna hai that has 0,1,2 child
        // 0-> seedha delete and return NULL
        // 1-> delete node and child node ko replace = return temp i.e upar se jo link aa rha usko child ko point krado 
        // 2-> left subtree se max val ya right subtree se min val nikal ke copy krdo node me
        // and us max/min value wale node ko delete
        return solve(root,key);
    }
};