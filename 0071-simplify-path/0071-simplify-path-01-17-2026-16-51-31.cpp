class Solution {
public:
    string simplifyPath(string path) {
        //stack me sirf name (string) store krunga
        //and wo str ko char se banao str+=path[i]
        // ... is treated as string
        // / = // = /// ..
        // . = curr directory hi hai = continue
        stack<string> st;
        int n = path.length();
        for(int i=0;i< n;i++){
            string str ="";   //har iteratn me str banao
            if(path[i]== '/'){
                continue;
            }
            while(i<n && path[i] != '/'){ //alpha,'.' ya '..' hai
                str+=path[i];  // 'h','o','m','e' ; '.', '.', '.'
                i++;
            }
            if(str ==".."){
                if(!st.empty())
                    st.pop();
            }
            else if(str =="."){
                continue; //curr directry hai
            }
            else{  //string ko push in st ->home, user
                st.push(str);  //home
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