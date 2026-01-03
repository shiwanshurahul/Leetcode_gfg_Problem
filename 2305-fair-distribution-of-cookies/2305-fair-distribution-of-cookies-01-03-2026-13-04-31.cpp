class Solution {
public:
int unfairness = 1e9;
int n;
void solve(vector<int>& cookies, int idx, vector<int> &children, int k){
    if(idx>= n){
        unfairness = min(unfairness,*max_element(children.begin(),children.end()));
        return;
    }

    int cookie = cookies[idx];  //this can go to any of the k child
    for(int i=0;i<k;i++){
        children[i] +=cookie;
        solve(cookies,idx+1,children,k);
        //after this recursion
        children[i] -= cookie;
    }
}   
    int distributeCookies(vector<int>& cookies, int k) {
        //bcktrackin -> pick then explore then skip then explore
        n = cookies.size();
        vector<int> children(k,0); //each children ke cookies
        //no need of sorting
        solve(cookies,0,children,k);
        return unfairness;
    }
};