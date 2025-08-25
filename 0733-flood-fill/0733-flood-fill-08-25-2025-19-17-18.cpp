class Solution {
public:
void dfs(int i,int j,vector<vector<int>>& image,int initialcolor,int color){
    int n =image.size();
    int m =image[0].size();
    if(i<0 || j<0 || i>=n || j>=m)
    return;
    if(image[i][j]!= initialcolor)   
    return;     
     image[i][j] =color;  //mark visited-> color krdo

     dfs(i+1,j,image,initialcolor,color);   //recusive call on neighbors
     dfs(i-1,j,image,initialcolor,color);
     dfs(i,j+1,image,initialcolor,color);
     dfs(i,j-1,image,initialcolor,color);

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
      //graph wale me dfs-> auto child
      //matrix wale me dfs-> i<0 || i>m || j<0 || j>n   

        //dfs strategy-> mark visited and then recursive call to possible neighbors -> tree me v yahi hota e.g. solve(root->left,-)
        //  solve(root->right);  and inme generally void hota return type 
        
        //connected same pixel ko color with given color
        int initialcolor =image[sr][sc]; 
        if(initialcolor!= color)        // 1!=2
        dfs(sr,sc,image,initialcolor,color);   //sare connected mark hoenge with color
        return image;       
    }
};