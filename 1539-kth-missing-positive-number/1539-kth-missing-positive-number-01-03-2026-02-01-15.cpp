class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //sorted arr hai
        int n = arr.size();
        int num = 1;
        int i=0; 
        // while(i<n && k!=0){
        //     if(arr[i]==num)
        //         i++;
        //     else
        //         k--;
        //     num++; //har bar        
        // }
        // while(k--){
        //     num++;
        // }
        // return num-1;

       //m2: b.s-> no of missing no = arr[i] - (i+1)
        int s = 0, e = n-1;
        while(s<=e){
            int mid = s + (e-s)/2;  
            int kitne_missing_no = arr[mid] - (mid+1);
            if(kitne_missing_no < k)
                s = mid+1;
            else
                e = mid-1;      
        }
        return s+k;
    }
};