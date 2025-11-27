class Solution {
public:
    string minRemoveToMakeValid(string s) {
      stack< int> st;
      for(int i=0;i<s.size();i++){
          if(s[i]=='('){
              st.push(i);
          }
          else if(s[i]== ')'){
               if(st.empty())
              s[i]= '!';
              else 
              st.pop();
          }
      }
      //extra '(' can remain in stack
      while(!st.empty()){
          s[st.top()]='!';
          st.pop();
      }
      //remove all  '@' from string
      s.erase(remove(s.begin(),s.end(),'!'),s.end());  
      return s;
    }
};