class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {   
        int n = arr.size(); 
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> v;
        int diff = 1e9;

        for(auto i=0;i<n-1;i++){
            diff = min(diff, abs(arr[i+1]-arr[i]) );
        }

        for(int i=0;i<n-1;i++){
            if(diff == (arr[i+1]-arr[i]))
                ans.push_back({arr[i],arr[i+1]}); 
        }
        return ans;  
    }
};