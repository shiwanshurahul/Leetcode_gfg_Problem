class Solution {
public:
int n = 0;
int get_pivot_idx(vector<int>& nums, int s, int e ){
    
    //ski duplicates -> apne nex elem se compar krte rho:
    while(s <e && nums[s] == nums[s+1]){
        s++;
    }
    while(s<e && nums[e] == nums[e-1]){
        e--;
    }
    //nw, both s and e are on unique no 
    // get_pivot idx
    while(s<e){
        int mid = (s+e)/2;
        if(nums[mid] < nums[e])
            e = mid;   //valid = stor this and goto left
        else
            s = mid+1;    
    }
    return s;  //idx of pivot elem
}
int binary_search(vector<int>&nums, int target, int s, int e ){
    while(s<=e){
        int mid = (s+e)/2;
        if(nums[mid] == target)
            return true;
        else if(nums[mid] > target)
            e = mid-1;
        else
            s = mid+1;        
    }
    return false;
}
    bool search(vector<int>& nums, int target) {
        //brute forc -> linear searc = o(n)
        // searc in Rotated Sorte array with duplicates
        //pivot_idx galat a rha jb duplicates ha arr me
        // = skip duplicates and fin pivot
        n = nums.size();
        // 0 to pivot-1 tk sorted and pivot se end tk sorted
       
        int pivot_idx = get_pivot_idx(nums,0,n-1);
        //pivot is the smalest elemt of arr
      
        bool x = binary_search(nums,target,0,pivot_idx-1);
        bool y = binary_search(nums,target,pivot_idx,n-1);
        return x || y;
       
    }
};