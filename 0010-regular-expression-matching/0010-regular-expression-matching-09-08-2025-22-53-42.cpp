class Solution {
public:
int solve(string& s, string& p, int i, int j){

    if(i<0 && j<0)  //dono ek sath khatam
        return true;

    if(i>=0 && j<0)  //string is remaining
        return false;
    
    if(i< 0 && j>=0){  //pattern is remaining
        if(p[j]=='*')
            return solve(s,p,i,j-2); //zero preceding elem
        return false;  //agar solve true ni aay toh
    }

    //  int k = j;
    //  while(k !=-1){   //only * is allowed
    //     if(p[k] !='*')
    //         return false;
    //     k--;
    //  }
    //  return true;



    if(s[i]== p[j] || p[j]=='.'){
        return solve(s,p,i-1,j-1);
    }
    else if(p[j]=='*'){
        bool ans = false;  
        ans |= solve(s,p,i,j-2);   //don't take/ zero preceding element
        if(s[i]==p[j-1] || p[j-1]=='.')   // use 1 or more times -> char match hoga string se tbhi loge na
            ans |= solve(s,p,i-1,j);

        return ans;
        }
       
   //else: no match
        return false;     
}
    bool isMatch(string s, string p) {
        //* se just pichla char ko zero or more bar le skte
        //e.g. ab* = a, ab, abb, abbb, abbbbbb
        return solve(s,p,s.length()-1,p.length()-1);
    }
};