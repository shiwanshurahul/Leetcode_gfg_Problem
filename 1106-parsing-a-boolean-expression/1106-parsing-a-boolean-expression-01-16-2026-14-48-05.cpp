class Solution {
public:
char solve(char op,vector<char>&v){
    if(op=='!'){
        return v[0] == 't' ? 'f' : 't';
    }//t hai toh f and vice-versa
    else if(op=='|'){
        for(auto it: v){
            if(it=='t')  //ek v t
                return 't';
        }
        return 'f';
    }
    else if(op=='&'){
        for(auto it: v){
            if(it=='f')  //ek v false
                return 'f';
        }
        return 't';
    }
    return 'a'; //never execute
}
    bool parseBoolExpr(string expression) {
        //  ')' ane pe '(' se yehan tak evalutate
        //() se pehle ek operator hoga jiske basis pe kro
        // !(&(f,t)) 
        int n = expression.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(expression[i]== ','){
                continue;
            }
            if(expression[i]==')'){
                //get expression b/w ()
                vector<char>v;
                while(!st.empty() && st.top() !='('){
                    v.push_back(st.top()); //f,t
                    st.pop();
                }
                st.pop(); //-> remove '('
                //operator lo -> &
                char op = st.top();
                st.pop();  //pop this op
                st.push(solve(op,v) );
            }
            else{
                st.push(expression[i]);
            }
        }
        return st.top()=='t' ? true : false;
    }
};