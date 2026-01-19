class Solution {
public:
    int longestValidParentheses(string s) {
        //longest continuous
        //"()(()" -> o/p is 2
        //"()(())" -> o/p is 6
        //")()())" -> o/p is 4
        int n = s.length();
        stack<int>st;
        st.push(-1);
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);  //index -> generally yahi store krte
            }    
            else if(s[i]==')'){
                if(!st.empty()){
                    st.pop(); //balanced = ()
                    if(st.empty())
                        st.push(i);
                    ans = max(ans,i-st.top());
                } 
            }    
        }
        return ans;
    }//"()(()"
    //     
};