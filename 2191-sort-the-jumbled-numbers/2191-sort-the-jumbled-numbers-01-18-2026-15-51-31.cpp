class Solution {
public:
string get_mapped_num(string str,vector<int>& mapping){
    string ans = "";
    for(int i=0;i<str.length();i++){
        int num = str[i] -'0'; //'9'-'0' = 9
        ans +=to_string(mapping[num]);
    }
    return ans;
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        //mapped val nikal ke sort krdo and keep 'i' taki track rkh sko
        // i ke basis pe if mapped_num same hai toh
        //"991" ka "669"
        //"338" ka "007"

        int n = nums.size();
        vector<pair<int,int>> v; //{mapped_num,i} 
        for(int i=0;i<n;i++){
            string mapped_str = get_mapped_num( to_string(nums[i]),mapping); //"991" ka "669"
            int mapped_num = stoi(mapped_str);
            v.push_back({mapped_num,i}); 
        }
        sort(v.begin(),v.end()); //based on first val   
        vector<int> ans;

        for(auto it:v){
            int original_idx = it.second;
            ans.push_back(nums[original_idx]);
        }
        return ans;

    }
};