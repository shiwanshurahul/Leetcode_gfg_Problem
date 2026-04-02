class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int cnt=0;
        //only unbalanced k cnt->  ][ = ']' ya '[' remaining ka (cnt+1)/2 
        // n/2 hai given 2ono, unbalalced part ka (cnt+1)/2 krdo
        for(auto c :s){
            if(c=='[')
                st.push(c);
            else if(!st.empty() && c==']')  //balance hai = no swap
                st.pop();   
            else     //c=']' and st is empty
                cnt++;
        }
        return (cnt+1)/2;   //or (st.size()+1)/2
    }
};