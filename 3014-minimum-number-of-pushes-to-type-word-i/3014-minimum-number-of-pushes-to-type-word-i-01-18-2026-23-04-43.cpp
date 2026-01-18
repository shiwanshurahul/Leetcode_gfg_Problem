class Solution {
public:
    int minimumPushes(string word) {
             //jitna kam btn press krna pde to type all char
        //"abcde" -> ek me dal doge (e.g.2 me) toh 1 + 2 + 3 + 4 + 5 = 15 press = alag alag me dal do toh 5 btn press (2,3,4,5,6) me 1 char
        // = alag alag me dalte rho (2-9) tak uske bad repaeat
        unordered_map<int,int>mp;
        int ans = 0;
        int assign_key = 2; //2 se 9 tak me dal skte char ko
        for(auto it: word){
            mp[assign_key]++;
            ans += mp[assign_key];
            assign_key++;  //2,3,4,5,6,7,8,9,2,3,4,5,7.

            if(assign_key > 9)
                assign_key = 2;
        }
        return ans;
    }
};