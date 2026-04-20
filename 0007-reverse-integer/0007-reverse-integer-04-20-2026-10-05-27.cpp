class Solution {
public:
    int reverse(int x) {
        long long int ans=0;
        while(x!=0){
            int rem =x%10;     //3 ,2, 1
            ans =ans*10 +rem;  //3 ,32, 321
            x =x/10;           //12,1
            if(ans>= INT_MAX || ans<=INT_MIN)
                return 0;
        }
        return ans;
    }
};