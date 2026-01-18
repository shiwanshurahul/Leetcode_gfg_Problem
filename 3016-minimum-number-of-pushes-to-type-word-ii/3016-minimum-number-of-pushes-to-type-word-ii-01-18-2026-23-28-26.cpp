class Solution {
public:
    int minimumPushes(string word) {
        //char can be duplicate
        //jitna kam btn press krna pde to type all char
        //"abcde" -> ek me dal doge (e.g.2 me) toh 1 + 2 + 3 + 4 + 5 = 15 press = alag alag me dal do toh 5 btn press i.e (2,3,4,5,6) me 1 char
        // = alag alag me dalte rho (2-9) tak uske bad repeat

        //jiska freq jyada hai usko pehle rkho 
        //e.g. aiiii -> 2 me rkh diya dono(pehle a fir i) = 1 + 2 + 2 + 2 + 2 = 9 presses ; if (i pehle rkha) then 1 + 1 + 1 + 1 + 2 = 6 press = min 
        // = freq ke basis pe sort in desc order me  
        //2-9 tak me rkh skte in phone

        vector<int> freq(26,0); //sare char ki freq stor
        for(auto it: word){
            freq[it-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>()); //sort w.r.t. freq
        int ans = 0;
        for(int i=0;i<26;i++){
            int fre = freq[i];
            int press = i/8 + 1;
            ans += (fre*press);
        }
        return ans;
    }
};