class Solution {
public:
    int minimumDeletions(string s) {
        //'a' ke bad 'b' aaye
        //invalid hai -> "ba" = b before a
        //jb v aisa ho toh remove krna pdega b ko

        int n = s.length();
        int cnt_b = 0;  //iske bad 'a' ni warna invalid 
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                cnt_b++;
            }    
            else if(s[i]=='a' && cnt_b !=0){  //"ba" hai
                cnt_b--;    
                ans++; //invalid cas -> remove b
            }    
        }
        return ans;
    }
}; 


