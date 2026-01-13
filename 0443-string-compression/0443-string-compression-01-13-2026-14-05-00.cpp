class Solution {
public:
    int compress(vector<char>& chars) {
        //i.p -> ["a","a","b","b","c","c","c","a"]
        //o.p-> ["a","2","b","2","c","3","a"]
        unordered_map<char, int> mp;
        vector<char> ans;
        int n = chars.size();
        int i = 0;
        while(i<n){
            char ch = chars[i];
            ans.push_back(ch);
            int cnt = 0;
            while(i<n && ch == chars[i]){
                cnt++;
                i++;
            }
            if(cnt==1){
                continue;
            }    
            else if(cnt<10){
                ans.push_back(cnt+ '0');    
            }
            else{  //cnt>10 e.g. 12, 102 -> write count as string
                    for(auto it: to_string(cnt)){
                        ans.push_back(it);
                    }
                    // while(cnt !=0){
                    //     int div = cnt/10;
                    //     int rem = cnt%10;
                    //     ans.push_back(div+ '0'); 
                    //     ans.push_back(rem+ '0'); 
                    // } 
            }    
        }
        for(auto it: ans){
            cout<<it<<endl;
        }
        chars.clear();
        chars = ans;
        return ans.size();
    }
};