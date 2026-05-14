class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
            return x;
        int s=0,e=x-1;
        int ans=0;
        while(s<=e){
            long long int mid =(s+e)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid>x)
                e=mid-1;
            else{
                ans = mid; //stor ans
                s=mid+1;   //chk in right sid = mor clos
            }
        }
        return ans;
    }
};