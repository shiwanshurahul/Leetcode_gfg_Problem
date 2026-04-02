class Solution {
public:
    string minRemoveToMakeValid(string s) {
        //balanced string likho
        stack<int> st; //idx store
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){  // '(' push krte generally
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty())
                    st.pop(); //balanced '(' and ')'
                else if(st.empty())
                    s[i] ='!';      
            }
        }

        //extra '(' ho skta st me
        while(!st.empty()){
            s[st.top()] ='!';
            st.pop();
        }

        //remove all '!'
        for(int i=0;i<s.length();i++){
            if(s[i]=='!'){
                s.erase(i,1);
                i--;  //firs is idx p chk
            }
        }
        return s;
    }
};