class Solution {
public:
bool dfs(vector<int>&arr, int i){
    if(i>=arr.size() || i<0 || arr[i]==-1)
        return false;

    if(arr[i]==0)
        return true;

    int val =arr[i];   //alag se vis arr v bana skte
    arr[i] = -1;   //mark visited
 
    return dfs(arr,i+val) || dfs(arr,i-val);       
}
    bool canReach(vector<int>& arr, int start) {
        //i+arr[i] or i-arr[i] ja skte
        //ekbar jo visit ho gya uspe wapas ni aana
        return dfs(arr,start);
    }
};