class Solution {
public:
typedef long long ll;
bool ispossible(vector<int>&piles, long long mid, int h){
    //mid = 6,
    ll time = 0;
    for(int i=0;i<piles.size();i++){
        time += (piles[i]/mid);    //3/6 = 0, 6/6=1, 7/6=1, 11/6= 1
        if(piles[i]%mid !=0)       //1 aaega
            time++;          //0->1,1->1,2->2,3->2  = 6<8
    }
    return time <=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        //b.s
        //koko can eat k bananas each hour
        //usko h hours tak me sb khane hai
        ll s =1;
        ll e = *max_element(piles.begin(), piles.end());
        ll ans = -1;
        //agar kisi k pe ho rh toh k+1,k+2, .. pe v hoga but u need min
        while(s<=e){
            ll mid = s + (e-s)/2;  //(1+11)/2 = 6
            if(ispossible(piles,mid,h)){
                ans = mid;  //store ans
                e = mid-1;  // goto left
            }
            else{
                s = mid+1;    
            }
        }
        return (int)ans;
    }
};