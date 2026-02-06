class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        //max_elem <=k*min_elem
        // return the minimum number of elements to remove
        // no of deletn = n-balanced substr
        int n = nums.size();
        sort(nums.begin(),nums.end()); 
        //[1,2,6,9], k=3

        int i=0;  //isse compr
        int ans = 0; //len of largst balanced arr
        for(int j=0;j<n;j++){ 
            if( (long long)(nums[j]) <=  (1LL *k* 1LL *nums[i]))
                ans = max(ans,j-i+1); //cur ans store and age check
            else  //i ko increa
                i++;
        }
        return n-ans; //no of deletn
    }//i=0, j=0 = ans = 1; i=0,j=1=ans=2 ; j=2->i=1ans=2;
};