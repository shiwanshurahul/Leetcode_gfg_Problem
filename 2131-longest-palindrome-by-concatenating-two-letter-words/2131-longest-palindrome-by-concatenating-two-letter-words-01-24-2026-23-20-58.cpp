class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // 3 cases: 
        //search krlo ki jis idx pe hai uska reverse exists
        //e.g. cl, lc = 4 + gg = 6
        //beech me 1 hi bar aa skta continous agar uski freq 1 hai toh e.g. aa  bb cc
        // continous hai >=2 e.g. aa aa 
        unordered_map<string,int> mp;
        for(auto it: words){
            mp[it]++;
        }
        int cnt=0;
        bool centerUsed = 0;
        for(int i=0;i<words.size();i++){
            string temp = words[i];
            string rev_str = words[i];
            swap(rev_str[0],rev_str[1]);  //reversed
            if(temp != rev_str){
            if(mp[temp] >0 && mp[rev_str] >0 ){
            cnt+=4;
            mp[temp]--;
            mp[rev_str]--;
            }
            }  
            else{         // temp == str hai   
            if(mp[temp] >=2){ //e.g. aa aa can use
                cnt+=4;
                mp[temp] = mp[temp] - 2;
            }
            else if( mp[temp] == 1 && !centerUsed){   //ek hi bar e.g. aa
            cnt+=2;
            centerUsed = true;
            }
        }
        }
        return cnt;
    }
};