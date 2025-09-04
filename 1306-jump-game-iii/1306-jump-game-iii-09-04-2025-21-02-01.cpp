class Solution {
public:
bool solve(vector<int>& arr, int i){
    if( i<0 || i>= arr.size() )   //out of bound
        return false;    

    if(arr[i] == -1)   //already marked
        return false;

    if(arr[i] == 0)
        return true;

    int jump = arr[i];  //to use
    arr[i] = -1;  //mark visited

    //dfs call to possible neighbors
    return solve(arr,i+jump) || solve(arr,i-jump);  //kahin se v true  
}
    bool canReach(vector<int>& arr, int start) {
        //jis v idx pe ho uske sare reach use kro ->No
        // jis v idx pe ho wo arr[idx] jitna 1 jump marega aage ya piche no intermediate  
        // = no use of for loop

         return solve(arr, start); //dfs
    }
};