class Solution {
public:
typedef long long ll;
int operation(int a,int b,string token){
    if(token=="*")
        return (ll)a*b;
    if(token=="+")
        return (ll)a+b;
    if(token=="-")
        return (ll)-a+b;
    if(token=="/")
        return (ll)b/a;
    return -1;
}
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for( string token: tokens){
            if(token=="*" ||  token=="+" || token=="-" || token=="/"){
                int a = st.top(); 
                st.pop();
                int b =st.top();
                st.pop();
                int res= operation(a,b,token);
                st.push(res);
            }
            else{
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};