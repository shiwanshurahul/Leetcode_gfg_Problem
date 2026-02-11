class Solution {
public:
    int partitionString(string s) {
        //no of substring jo unique hai bol rha = 
        // todne ka cnt rkh lenge jb duplicate hai subtrin
        //char repeat ho substrin me
        //toh todlo curr substr ko i.e cnt++ and mp v delet
        //ab ac ab a = 4
        //gredy
        int cnt =0;  //substrin todne ka cnt
        int n =s.length();
        int i=0;
        unordered_map<char,int> mp;
        while(i<n){
            char ch = s[i];
            if(mp.find(ch)!=mp.end()){ //exist in mp
                cnt++; //3 bar break hua
                mp.clear(); //sare char delete
            } //only unique
            mp[ch]=i; //a=0,b=1 ;a=2;c=3 ; a=4,b=5; a=6
            i++;
        }
        return cnt+1;

    }
};