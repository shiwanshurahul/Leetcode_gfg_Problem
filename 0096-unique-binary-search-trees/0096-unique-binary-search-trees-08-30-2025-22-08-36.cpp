class Solution {
public:
    int numTrees(int n) {
        //root ke pas total unique b.s.t = no of unique b.s.t from left child * no of unique b.s.t from right child
        //b.s.t ->  All values in its left subtree are strictly less than the node's own value. 
            //All values in its right subtree are strictly greater than the node's own value. 
            //  This property applies recursively to all subtrees within the BST.

            //logic:
            //1 se leko n tk sbko ek ek krke root manlo b.s.t ka
            //f(0) = 0
            //1,2,3,4,5,.., i, ,.., n
            //i ke left part me 1 to i-1 nodes hoenge = (i-1) nodes in left subtree
            //i ke right part me i+1 to n nodes hoengi = (n-i)  nodes in right subtree 

             //f(n) ->  f(i-1) * f(n-i) for all i,  where i->(1 to n) tak

             vector<int> dp(n+1,-1);
             return solve(n,dp);

    }
    int solve(int n, vector<int> &dp){
        if(n==0)
            return 1;

        if(dp[n] != -1)
            return dp[n];

        int ans = 0;

        for(int i=1;i<=n;i++){  //think i as root node
            ans += solve(i-1, dp) * solve(n-i, dp);   //left subtree * right subtree
        }

        return dp[n] = ans;    
    }
};