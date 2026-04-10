class Solution {
public:
//express base case in i and j
//explor all cases
//retur max,min,sum, ..
int n;
vector<string> ans;
bool isvalid(string str){
    if(str[0]=='0')
        return false;
    return stoi(str) <=255;    
}
void solve(string&s, int i, string str, int parts){
    if(i==n && parts == 4){  //n-1 tk strin and last char is '.'
        str.pop_back(); //last is '.'
        ans.push_back(str);
        return;
    }
    if(parts>4)
        return;

    if(i+1 <= n)
        solve(s,i+1, str + s.substr(i,1)+".", parts+1);

    if(i+2<=n && isvalid(s.substr(i,2)) )
        solve(s,i+2, str + s.substr(i,2)+".", parts+1);

    if(i+3 <=n && isvalid(s.substr(i,3)))
        solve(s,i+3, str + s.substr(i,3)+".", parts+1);        

}
    vector<string> restoreIpAddresses(string s) {
        //max 4 parts ; digit b/w 0-255 ; no traling 0
        //1-3 len ke bad '.' lga skt = lagake dekhlo 3no tk 
        n = s.length();
        if(n>12)
            return {};
        string str= "";
        int parts=0;
        solve(s,0, str,parts);
        return ans;
    }  //str + s.substr(i,2)+"."
};