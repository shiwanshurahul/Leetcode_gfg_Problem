class Solution {
public:
    int minimumDeletions(string s) {
        //'a' ke bad 'b' aaye
        //invalid hai -> "ba" = b before a
        //jb v aisa ho toh remove krna pdega
        //keep track of inalid cas

        int n = s.length();
        int cnt_b = 0;  //iske bad 'a' ni warna invalid 
        int ans = 0;
        // for(int i=0;i<n;i++){
        //     if(s[i]=='b'){
        //         cnt_b++;
        //     }    
        //     else if(s[i]=='a' && cnt_b !=0){  //"ba" hai
        //         cnt_b--;    
        //         ans++; //invalid cas
        //     }    
        // }
        // return ans;

        //m2: 
        //stack -> keep valid string in stack

        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='a' && !st.empty() && st.top()=='b'){ //'ba'
                st.pop();
                ans++; //invalid
            }
            else{               
                st.push(s[i]);
            }
        }
        return ans;
    }
}; 


