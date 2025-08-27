class Solution {
public:
int solve(vector<int> nums1, vector<int> nums2, int i, int j){
    cout<<"hii";
    if( i>= nums1.size() || j>= nums2.size() )
        return 0;

    if(nums1[i] == nums2[j])
        return 1 + solve(nums1,nums2,i+1,j+1);
    
    else
        return max(solve(nums1,nums2,i+1,j), solve(nums1,nums2,i,j+1) );   
    
}
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        //lcs
        return solve(nums1,nums2,0,0);
    }
};