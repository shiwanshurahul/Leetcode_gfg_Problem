class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //sorted order hai
       for(int i=0;i<arr.size();i++){
        if(arr[i]<=k)
            k++;
       }
       return k;
        
    }//1!=2 =k=4;cnt=2
    //cnt=arr[i] = 3
    //cnt = arr[i] = 4
    //5 != 7 = k=2,cnt=7
    //8!=11 = 
};