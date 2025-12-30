class Solution {
public:
// backtracking -> pick then explore then skip then explore 
vector<vector<int>> ans;
vector<int> temp;
int n;

// bool same_cnt( vector<int>&t){
//     //funct to check both have same elem with same freq;
//     vector<int> tmp = t;
//     sort(tmp.begin(),tmp.end());
//     return nums_copy == tmp;
// }
void solve(vector<int>&nums, int i, unordered_map<int,int> &mp){
    if(temp.size()==n ){         //block [1,1,1], ..
        ans.push_back(temp);
        return;  //n ho gya size toh return
    }
    
    if(i>n)
        return;
  
    for(auto it: mp){  //jo elem hai unpe iterate
        int num = it.first;
        int cnt = it.second;
        cout<<num<<cnt<<endl;
        if(cnt == 0 )
            continue;  //already explored
        temp.push_back(num);
        mp[num]--;
        solve(nums,i+1,mp);   //i+1 param ni lene se v chlega
        //after this recursive call:
        temp.pop_back();
        mp[num]++;  
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //nums ke elem can be duplicate = for loop me cond ni aaega
        //vector sort krke compare krne me tle
        //pick then explore then skip then explore
        //all elem = for loop chalao


           // for(int i=0;i<n;i++){  //1 recirsive call in for loop
    //     // if( find(temp.begin(),temp.end(),nums[i]) == temp.end() ){
    //         temp.push_back(nums[i]);
    //         solve(nums,i+1);
    //         //after this recursive call:
    //         temp.pop_back();
    //     // }
    // }     

        n = nums.size();
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        solve(nums,0,mp); //bina i+1 ke v chalega i.e no idx param
        return ans;
    }
};