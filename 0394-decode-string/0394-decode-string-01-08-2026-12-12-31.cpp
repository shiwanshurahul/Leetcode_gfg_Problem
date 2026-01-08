class Solution {
public:
    string decodeString(string s) {
        //e.g. 3[a2[c]] = 3[acc] = accaccacc
        //']' ko chor ke sb kuch st me store 
        //jaise hi ']' aaye string me pop in stack until st.top() =='['
        //jitni bar number aaye (0- 9) utna bar * o/p str 
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i] !=']'){ 
                st.push(s[i]);   //st-> 3 [ a ; 2 [ a b c
            }
            else{  //s[i]==']' hai
                string str;
                while(!st.empty() && st.top()!='['){
                    str = st.top() + str;     // str = a
                    st.pop();
                }   
                //str me mere pas '[' and  ']' ke beech ka str hai  
                st.pop();  // '[' ko toh hatao
                //ab num ka socho jo [] ke bahar hota ->utni bar string repeat
                string k;
                while(!st.empty() && st.top()>= '0' && st.top() <= '9'){  //check char is a digit
                   k = st.top() + k; st.pop(); 
                  //VVI step: e.g.'12' ni toh pehle 2 bar * and then 1 bar *
                }
                //str ko k bar st me dalo  
                int digit = stoi(k);
                while(digit--){
                    for(int j=0;j<str.length();j++){
                        st.push(str[j]);
                    }
                }
            }  //end of else
        }  //end of for loop
        string ans;
        while(!st.empty()){
            ans = st.top()+ ans;
            st.pop();
        }
        return ans;
    }
};