class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i=1,j=0;
        while(i<= n && j<target.size()){
            ans.push_back("Push");
            if(i==target[j]){
                i++;j++;
            }
            else{
                ans.push_back("Pop");
                i++;
            }
        }
        return ans;
    }
};