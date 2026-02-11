class Solution {
public:
    int partitionString(string s) {
 //char repaet ho toh ek substring me toh substring  todlo i.e cnt++;
        //ab ac ab a =4
               int cnt =0;
               int n =s.length();
               int i=0;
               unordered_map<char,int> mp;
               while(i<n){
                    char ch =s[i];
                    if(mp.find(ch)!=mp.end()){
                    cnt++;
                    mp.clear();
                    }
                    mp[ch]==i;
              i++;
               }
               return cnt+1;

    }
};