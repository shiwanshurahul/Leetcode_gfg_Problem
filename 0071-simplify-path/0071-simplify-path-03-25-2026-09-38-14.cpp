class Solution {
public:
    string simplifyPath(string path) {
        //stack me sirf name (string) stor 
        //and wo str ko char se banao str+=path[i]
        // .. pe pop from stk
        // ... is treated as string
        // .. hoga path[i] and path[i+1] dono pe '.' = str banake chk  
        // / = // = /// .. treat as single /
        // . = curr directory hi hai = continue
        stack<string> st;
        int n = path.length();
        for(int i=0;i< n;i++){
            string str ="";   //har iteratn me str banao
            if(path[i]== '/'){  //ye '/' khudse jod lena
                continue;
            }//else string banao //alpha,'.'. '..'. '....', .. 
            while(i<n && path[i] != '/'){ 
                str+=path[i];  // 'h','o','m','e' ; '.', '.', '.'
                i++;
            }  // '/' hai
            if(str ==".."){
                if(!st.empty())
                    st.pop();
            }
            else if(str =="."){
                continue; //curr directry hai
            }
            else{  //string ko push in st ->home, user, ...
                st.push(str);  //home, foo
            }
        }//end of for loop
        string ans ="";
        while(!st.empty()){
            ans='/'+ st.top()+ans;
            st.pop();
        }
        return ans.size() > 0 ? ans : "/";

    }
};