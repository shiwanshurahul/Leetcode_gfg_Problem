class Solution {
public:
    int minDeletion(vector<int>& nums) {
    // since we have to find the minimum deletions, we dont have to actually delete the elements , we just have to count those elements.
    //  If we delete the element and shift all the elements towards left ,it will cause time limit exceeded.
    //  To handle above case we can  observe one thing that, if we delete some element at a certain position then the indices of all the elements towards the right will get inverted means the odd index will become even and the even will become odd.
    // In the end checking if the vector size if even or odd, if it is even simply return or else if it is odd then decrement result by 1 since we have to remove one element to have the vector size even.
        int n = nums.size();
        int flag = 1;
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if( i%2 == 0 && nums[i] == nums[i+1] && flag == 1){
                ans++;
                flag = !flag;  //ek delete kiya toh uspe mat jao
            }  
            else if(i%2 == 1 && nums[i] == nums[i+1] && flag == 0){
                ans++;
                flag = !flag;
            }  
        }
        //odd len hai toh last ka hatao
        int x = n-ans;
        return x%2 == 0 ? ans : ans+1;
    }
};