class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        //sort krna pdega bcz linear se ho skta ki additionalRocks 
        //stat me khatam ho jaye and end me chote capaciy wale bags the
        int n = capacity.size();
        int ans = 0;
        vector<int> cnt(n,0);  //store remainin
        for(int i=0;i<n;i++){
            cnt[i] = capacity[i] - rocks[i];
        }
        //max fill krna hai = sort in ascending
        sort(cnt.begin(),cnt.end());

        for(int i=0;i<n;i++){
            if(cnt[i] <= additionalRocks){
                ans++; //isko full capacit tk bharo
                additionalRocks = additionalRocks - cnt[i]; 
            }
        }
        return ans;
    }
};