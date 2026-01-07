class Solution {
public:
int binary_search(vector<int>& nums,int s,int e, int target){
        int mid;
        while(s<=e){   //eval wo wala case v jb s==e ho
            mid = s+(e-s)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] >target){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        return -1;
}
int get_pivot(vector<int> &nums){  
    int s=0, e=nums.size()-1;
    int mid;
    while(s<e){
        mid = s+(e-s)/2;
        if(nums[mid] <nums[e]){   //store ans go left
            e =mid;
        }
        else{
            s = mid+1;
        }
    }
    return s; //index; for pivot elem -> nums[s]  
}
    int search(vector<int>& nums, int target) {
        //find pivot -> smallest element
        //then, 0 to pivot-1 tk me b.s and pivot to last me b.s
        long int pivot = get_pivot(nums);  //pivot idx

        long int x = binary_search(nums,0,pivot-1,target); 
        long int y = binary_search(nums,pivot,nums.size()-1,target);
  
        if(x == -1)
            return y;
        return x;

    }
};