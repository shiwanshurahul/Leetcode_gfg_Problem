class Solution {
public:
    int largestVariance(string s) {
        //dono ka cnt hona chhaiye aisa ni sirf ek char ka
        //brute force -> sare char me compare krlo pair kr ke
        //e.g 'a' -> 'b','c','d',..  -> first_cnt
        //fir 'b' -> 'a','c',..      -> second_cnt
        //if second_cnt >first_cnt = -ve = 0 krdo dono ke cnt ko = kadane
        //udhar subarray idhar substring
        //"abb" -> 'a' -> 'b' :0th pe 'a' ka cnt 1; 1st pe dono ka cnt 1 ; 2nd pe a ka cnt 1 and b ka 2 = -1 = 0 cnt dono ka
        //    -> 'b' -> 'a' : 0th pe dono ka cnt 0; 1st pe a ka cnt 1 ; 2nd pe a ka cnt 2 and b ka still 0 hai  = 2-0 = wrong
        // = cnt 0 ho ja rha toh track kaise rkhoga = seen_second var;
        vector<int> cnt(26,0);  //kon konse char present hai s me
        for(auto it: s){  
            cnt[it-'a']++;  //marked as present
        }
        int ans = 0; 
        for(char first='a';first<='z';first++){
            for(char second='a';second<='z';second++){
                if(cnt[first-'a'] == 0 || cnt[second-'a'] ==0)
                    continue;  //not present in strin
                int first_cnt = 0;    //'a'  //each pair pe
                int second_cnt = 0;   //'b'
                int seen_second = 0;  
                for(auto ch: s){ 
                    if(ch == first)
                        first_cnt++;
                    else if(ch == second)
                        second_cnt++;

                    if( second_cnt>0 )
                        ans = max(ans, first_cnt-second_cnt);
                    else if(seen_second) //1
                        ans = max(ans,first_cnt-1);

                    if(second_cnt > first_cnt){
                        second_cnt = 0;
                        first_cnt = 0;
                        seen_second = 1;  //warna 0 ho jaega and wrong for abb
                    }        
                }
            }
        }
        return ans;

    }
};