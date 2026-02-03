class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        //similar as 209 with negative no's
        //variable size window = j-i+1 is the o/p
        //2 bar ans nikalne ki kos

        //don't use sliding window as negative no 

        //e.g. nums = [84,37,32,40,95], k = 167
        //o/p: 3
        //expected o/p: 3 
        //e.g.2. nums = [84,-37,32,40,95], k = 167
        //o/p: 5
        //expected o/p: 3 = [32,40,95] ->simple slding windo wrong for this 

        //value dip ho rhi fir increas ho rhi 84, -37 fir  32,40,95
        // = dip se pehle ki values remove krdo
        // = increasing order me rkho values = monotonic stk /dq
        //with cumulative sm = nice approa

        int n = nums.size();
        int i=0,j=0;
        vector<long long> sum(n,0);  //cumulative sum ha
        int ans = 1e9;

        deque<int> dq; //stores idx in monotonic increasin order only

        while(j<n){  //i ko no use
            if(j == 0)
                sum[j] = nums[j];
            else
                sum[j] =  sum[j-1] + nums[j];  //cumulative sum   
           
            if(sum[j] >= k)  //cumulativ sum stored in j is >=k
                ans = min(ans, j+1); 
            
            //check if need to shrink
            while(!dq.empty() && sum[j] - sum[dq.front()] >= k ){
                ans = min(ans, j-dq.front());
                dq.pop_front();
            }
            //check monotonic nature break ni hai na:
            while(!dq.empty() && sum[j] <= sum[dq.back()] ){
                dq.pop_back();
            }
            dq.push_back(j); //har bar
            j++;
        }
        return ans == 1e9 ? -1 : ans ;







    //     int ans = 1e9;
    //     while(j<n){
    //         sum+= nums[j];
    //         if(sum < k){
    //             j++;
    //         }
    //         else if(sum == k){
    //             ans = min(ans,j-i+1);
    //             j++;
    //         }
    //         else if(sum>k){
    //             while(sum>k){
    //                 ans = min(ans,j-i+1);
    //                 sum -=nums[i];   //remove caln for i
    //                 i++;             //slide the window 
    //                 if(sum>=k)  
    //                     ans = min(ans,j-i+1);
    //             }
    //             j++;    
    //         }
    //     }
    //     return ans == 1e9 ? -1 : ans;
     }
};