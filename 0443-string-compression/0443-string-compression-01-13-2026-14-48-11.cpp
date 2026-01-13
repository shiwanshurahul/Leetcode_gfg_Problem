class Solution {
public:
    int compress(vector<char>& chars) {
        //i.p -> ["a","a","b","b","c","c","c","a"]
        //o.p-> ["a","2","b","2","c","3","a"]
       
        // vector<char> ans;
        int n = chars.size();
        int i = 0;
        // while(i<n){
        //     char ch = chars[i];
        //     ans.push_back(ch);
        //     int cnt = 0;
        //     while(i<n && ch == chars[i]){
        //         cnt++;
        //         i++;
        //     }
        //     if(cnt>1){  //cnt>10 e.g. 12, 102 -> write count as string
        //         for(auto it: to_string(cnt)){
        //             ans.push_back(it); //-> direct ye likho sb ke liy
        //         }
        //         // while(cnt !=0){ -> 100?
        //         //     int div = cnt/10;
        //         //     int rem = cnt%10;
        //         //     ans.push_back(div+ '0'); 
        //         //     ans.push_back(rem+ '0'); 
        //         // } 
        //     }    
        // }
        // for(auto it: ans){
        //     cout<<it<<endl;
        // }
        // chars.clear();
        // chars = ans;


        //m2: -> modifying the i/p array
       
        int write = 0; 
        while(i<n ){
            char ch = chars[i];
            int cnt = 0;
            while(i<n && ch == chars[i]){
                cnt++;
                i++;
            }//i=2 = 'b' ; i=4= 'c';
            chars[write++] = ch;  //'a','2','b','2','c','3'
            if(cnt>1){
                for(auto it: to_string(cnt)){  //sare cnt ke cases
                    chars[write++] = it;
                }
            }
        }

        return write;
    }
};