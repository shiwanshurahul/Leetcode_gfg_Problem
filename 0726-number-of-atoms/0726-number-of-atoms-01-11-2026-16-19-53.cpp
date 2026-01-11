class Solution {
public:
    string countOfAtoms(string formula) {
        //similar to Decode String
        int n = formula.length();
        stack<unordered_map<string, int> > st;
        st.push(unordered_map<string, int> ());

        int i=0;
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            }
            else if(formula[i]==')'){
                unordered_map<string,int> curr = st.top();
                st.pop();
                i++;
                //aage ka digit nikalo: (OH)2 -> 2
                string k;
                while(i<n && isdigit(formula[i])){
                    k+= formula[i++];
                }
                //k times multiply kro curr mp me k digit ko and then merge it with map existing in stack
                if(!k.empty()){
                    int digit = stoi(k);
                    for(auto it: curr){
                        curr[it.first] = it.second * digit; //0:2 ; 
                    }
                }
                //merge:
                for(auto it: curr){
                    st.top()[it.first] += it.second;
                }

            } 
            else{  //Mg; K4
                string s;
                s+= formula[i];
                i++;
                while(i<n && isalpha(formula[i]) && islower(formula[i])){  //g
                    s+= formula[i];
                    i++;
                }
                string k; //4
                while(i<n && isdigit(formula[i])){
                    k+=formula[i++];
                }  //but what if only k is there -> cnt is 1
                int digit = k.empty() ? 1 : stoi(k);
                st.top()[s] += digit;  // merge it with map existing in stack 
            }
        }//end of loop
        map<string, int> mp(begin(st.top()), end(st.top()));  //sorted way me
        string ans;
        for(auto it: mp){
            string elem = it.first;
            ans += elem;
            int cnt = it.second;
            if(cnt >1)
                ans += to_string(cnt);
        }
        return ans;


    }
};