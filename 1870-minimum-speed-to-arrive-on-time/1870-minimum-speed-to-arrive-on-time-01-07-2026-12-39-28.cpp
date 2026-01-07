class Solution {
public:
bool is_possible(int s, int e, int speed, vector<int>&dist, double hour, int n){
        //mid is speed
        double time = 0;
        for(int i=0;i<n;i++){
             if(i == n-1)  //last train ko ceil me ni krna
                time += (double) ((double)dist[i]/(double)speed);    
            else    
                time += ceil((double)dist[i]/(double)speed);    
        }
        return time <= hour;
}
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s = 1;
        int e = 1e7;
        int ans = -1;

        while(s<=e){
            int mid = s + (e-s)/2;
            if(is_possible(s,e,mid,dist,hour,dist.size())){
                ans = mid;  //store ans and go left
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};