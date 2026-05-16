class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        //sort krna pdega bcz linear se ho skta ki additionalRocks 
        //star me khatm ho jaye and end me chote capaciy wale bags the
        int n = capacity.size();
        int ans = 0;
        vector<int> remainin(n,0);  //store remainin
        for(int i=0;i<n;i++){
            remainin[i] = capacity[i] - rocks[i];
        }    
        // remainin = [1,1,0,1] = 1 bag alread filed hai
        //max fil krna hai = sort in ascendin
        sort(remainin.begin(),remainin.end());  // [0,1,1,1]

        for(int i=0;i<n;i++){
            if(remainin[i] <= additionalRocks || remainin[i] == 0 ){
                ans++; //isko full capacit tk bharo, filed ha
                additionalRocks = additionalRocks - remainin[i]; 
            }
        }
        return ans;
    }
};