class Solution {
public:
    int findTheWinner(int n, int k) {
        //arr lelo -> n+k-1 elem delete kro
        //cycle ke liye %size lelo -> decrease kr rhe
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = i+1;  //1,2,3,4,5
        }
        int i=0;
        while(arr.size()> 1){ //o(n)
            int idx = (i+k-1)%arr.size();  //remove this idx
            arr.erase(arr.begin()+idx); //o(n) opern
            i=idx;  //quest me bola hai deleted ke bad wala lo
        }  //khud delete hoga and arr left shift hoga
        return arr[0]; //ek hi bacha hai elem
    }
};