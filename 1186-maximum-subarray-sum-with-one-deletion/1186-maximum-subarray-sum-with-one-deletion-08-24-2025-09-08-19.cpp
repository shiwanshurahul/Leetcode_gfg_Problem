class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int delete_1 = 0, no_delete = arr[0];
        int ans = arr[0];

        for(int i=1;i<arr.size();i++){
            delete_1 = max(no_delete,delete_1 + arr[i]);
            no_delete = max(no_delete+arr[i], arr[i]);
            ans = max(ans, max(delete_1, no_delete));
        }
        return ans;
    }
};