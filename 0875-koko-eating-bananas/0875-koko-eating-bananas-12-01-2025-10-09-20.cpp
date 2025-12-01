class Solution {
public:
bool ispossible(vector<int>&piles, long long mid, int h){
    
    long long time = 0;
    for(int i=0;i<piles.size();i++){
        time += (piles[i]/mid);
        if(piles[i]%mid !=0)
            time++;
    }
    return time <=h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        //b.s
        //koko can eat k bananas each hour
        //usko h hours tak me sb khane hai
        long long s=1, e = *max_element(piles.begin(), piles.end());
        long long ans = -1;
        //agar kisi k pe ho rha toh k+1,k+2, .. pe v hoga but u need min
        while(s<=e){
            long long mid = s + (e-s)/2;  //(1+11)/2 = 6
            if(ispossible(piles,mid,h)){
                ans = mid;  
                e = mid-1;  //store ans and goto left
            }
            else{
                s = mid+1;    
            }
        }
        return (int)ans;
    }
};