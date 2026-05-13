class Solution {
public:
    int minAddToMakeValid(string s) {
        //jo no of ilegal hai wahi ans hai
        //generaly st me '(' pus krte and pop when ')' = balancd
        stack<char> st;
        int cnt=0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
            }
            else if(s[i]==')' && !st.empty()){  //balanced
                st.pop();
            }
            else{    //s[i] =')' && st is empty
                cnt++;
            }
       }
        return cnt+st.size();


    }
};