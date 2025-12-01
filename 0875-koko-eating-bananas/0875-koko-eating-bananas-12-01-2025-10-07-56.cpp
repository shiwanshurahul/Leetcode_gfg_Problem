class Solution {
public:
bool solve(int mid,vector<int>& piles, int h){
    long int total =0;
    for(int i=0;i<piles.size();i++){
       total += ceil((double)piles[i]/mid);
    }
    return(total <= h);
   
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int k =1e9;
        sort(piles.begin(),piles.end());
       //k should lie b/w 1 and arr[n-1]
       int s=1,e= piles[piles.size()-1];
       while(s<=e){
           int mid =(s+e)/2;
           if(solve(mid,piles,h)){
                k =min(mid,k);
                e= mid-1;          
       }
       else {
           s =mid+1;
       }
       }
       return k;
    }
};