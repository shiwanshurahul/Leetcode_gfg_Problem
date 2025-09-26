class Solution {
public:
bool ispossible(vector<int>&weights,int mid,int days){
 
 int cnt = 1;
 int last =0;
 for(int i=0;i<weights.size();i++){
     if(weights[i]+ last<=mid){
         last +=weights[i];
     }
     else{
         cnt++;
         if(cnt>days || weights[i]>mid)
         return false;
         last =weights[i];
     }
 }
 return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());//4
        int e = accumulate(weights.begin(), weights.end(), 0);//16
        int ans=0;
        while(s<=e){
            int mid =(s+e)/2;
            if(ispossible(weights,mid,days)){
                ans =mid;
                e =mid-1;  //search for solution as left as possible
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};