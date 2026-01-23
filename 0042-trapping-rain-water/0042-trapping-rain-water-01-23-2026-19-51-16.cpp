class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        //min height of(l,r) - height[i] hi store kr skta ith building
        //e.g. [4,1,6] pe jama hoga = min(4,6)-4 + min(4,6) - 1 + min(4,6) - 6 =  0 + 3 + 0 = 3 units
        //4 pe 0 and 6 pe 0 hoga
        //store each building ka left max and right max
        //i.e i se pehle sbse badi value and i ke bad sbse badi val of arr

        //then take min of both - curr[i]
        vector<int> maxl(n);  //max of left abtak
        vector<int> maxr(n);  //max of right 
        vector<int> water(n); //net water on each i

        maxl[0] = height[0];
        for(int i=1;i<n;i++){
            maxl[i] = max(maxl[i-1],height[i]);          
        }  //0 1 1 2 2 2 2 3 3 3 3 3 ; 4 4 4 4 4 4-> repeat hoti rhegi max

        maxr[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            maxr[i] = max(maxr[i+1], height[i]);             
        }  // 5 5 5 5 5 5
        //ith building pe kitna water kitna jama hoga = min(l,r) - height[i] of building
        for(int i=0;i<n;i++){
            water[i] = min(maxl[i], maxr[i]) -height[i];
        }
        int sum=0;
        for(int i=0;i<n;i++){
            // if(water[i]<0)  //-ve height
            //     continue;
            sum+=water[i];
        }
        return sum;
    }
};