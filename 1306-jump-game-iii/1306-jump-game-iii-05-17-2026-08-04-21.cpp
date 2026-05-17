class Solution {
public:
bool dfs(vector<int>&arr, int i){
    if(i>=arr.size() || i<0 )
        return false;

    if(arr[i]==-1)   //alread visitd
        return false;    

    if(arr[i]==0)
        return true;

    int val = arr[i];   //alg se vis arr v bana skte
    arr[i] = -1;   //mark visited
 
    return dfs(arr,i+val) || dfs(arr,i-val);       
}
    bool canReach(vector<int>& arr, int start) {
        //i+arr[i] or i-arr[i] ja skt
        //reah an idx with val=0
        //ekbr jo visit ho gya uspe wapas ni ana
        // = dfs aply
        return dfs(arr,start);
    }
};