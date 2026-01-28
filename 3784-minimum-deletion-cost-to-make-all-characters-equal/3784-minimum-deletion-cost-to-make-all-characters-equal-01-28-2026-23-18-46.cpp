class Solution {
public:
typedef long long ll;
    long long minCost(string s, vector<int>& cost) {
        //min total deletin cost = max deleting cost wale char ko ignor
        //string me bas ek hi char rkh skte, freq kitni v ho skti
        //e.g. a ; aaa ; zzzzzz; kk;
        // = kisi ek hi char ko rkho
        // = sbko delete krne ka try ek ek krke and min rkhlo
        int n =s.length();
        ll ans = 1e15;
        for(auto it='a';it<='z';it++){
            ll deletion_cost = 0;
            for(int i=0;i<n;i++){
                if(s[i] != it)  //not same char
                    deletion_cost += cost[i]; //delete kro 
            }
            ans = min(ans,deletion_cost);
        }
        return ans;    


    }
};