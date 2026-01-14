class Solution {
public:
static bool cmp(char &a, char &b){
    return a<b; //ascending order -> default v yahi hota 
}
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end(),cmp);
            return s;
        }
        //else:
        int n = s.length();
        string ans=s;
        s = s+s; //cbacba
        int i=0;
        while(i<n){
            ans = min(ans,s.substr(i,ans.length())); //(0,3) ;(1,4) ; (2,5)
            i++;
        }
        return ans;

    }
};