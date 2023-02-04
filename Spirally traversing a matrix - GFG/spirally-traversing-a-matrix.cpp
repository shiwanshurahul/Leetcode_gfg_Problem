//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> v;
        int l =0, ri = c-1;                    //  l   ri
        int t =0, b =r-1;                    // t[1,2,3]
        int d=0;                            //   [4,5,6]   
        while(l<=ri && t<=b){               //  b[7,8,9]
            if(d==0){           //      o/p->  //1 2 3 // row d =0
               for(int i=l;i<=ri;i++)         //6 9 // col d =1
            v.push_back(matrix[t][i]);       // 8 7 // row d=2   
                t++;                       // 4   //col d =3
                d=1;
            }
                else if(d==1){
                    for(int i=t;i<=b;i++){
                        v.push_back(matrix[i][ri]);
                }
                    ri--;
                    d=2;
                }
                else if(d==2){
                    for(int i=ri;i>=l;i--){
                        v.push_back(matrix[b][i]);
                }
                b--;
                d=3;
                }
                else if(d==3){
                    for(int i=b;i>=t;i--){
                        v.push_back(matrix[i][l]);
                        }
                        l++;
                    d=0;
                }
        }
        return v;
        // code here 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends