class Solution {
public:
 // * ->can be '(', ')', ''
    // ())* -> false
    // *(())(* -> true
    //(* ->true; )* ->false, *) -> true
    bool checkValidString(string s) {

    //problem is * ka pta ni koi sa v ho skta 3no me se

    //2 stack lelo 1 for '(' and other for '*' & dono me idx store of respective
    //return true of st1 becomes empty in last bcz '*' is '' in that scenario
   //valid -> if * is before ')' 

        stack<int> st; stack<int> asterisk_st;
        for (int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);  //idx store
            } 
            else if(s[i]=='*'){
                asterisk_st.push(i);  //idx store
            }
            else{       // ')' hai
                if(!st.empty()){
                    st.pop(); //balanced for that particular s[i] = ')'
                }
                else if(!asterisk_st.empty()){        
                        asterisk_st.pop();
                    }
                    else{
                        return false;
                    }
                }
        }
        while(!st.empty() && !asterisk_st.empty()){
            if(st.top() > asterisk_st.top()){
                return false;
            }
            st.pop();
            asterisk_st.pop();
        }
        return st.empty();
    }
};