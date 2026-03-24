class Solution {
public:
bool ispossible(vector<int>&weights,int mid,int days){
    //mid = 10, 6, 4, 5
    int day = 1;
    int sum = 0;
    for(int i=0;i<weights.size();i++){
        if(weights[i]+ sum<=mid){  //same day
            sum += weights[i];
        } 
        else{  //nxt dy
            day++;
            if(day>days || weights[i]>mid)
                return false;
            sum = weights[i];
        }
    }
    return true;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end()); //4
        int e = accumulate(weights.begin(), weights.end(), 0); //16
        int ans=0;
        while(s<=e){
            int mid =(s+e)/2;
            if(ispossible(weights,mid,days)){
                ans = mid;
                e = mid-1;  //store ans and then go to left possible
            }
            else{
                s = mid+1;
            }
        }
        return ans;
    }
};