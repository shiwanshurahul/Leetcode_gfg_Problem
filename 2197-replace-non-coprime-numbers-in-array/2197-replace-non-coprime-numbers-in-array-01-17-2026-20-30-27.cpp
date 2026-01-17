class Solution {
public:
typedef long long ll;
int get_gcd(ll a,ll b){
    if(b==0)
        return a;
    return gcd(b,a%b);    
}
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        //non co-prime = 1 ke alawa v divisor ho
        //adjacent ka nikalte rho = st me rkhlo
        //jb tak merge ho krte rho
        //lcm = product of 2 numb/gcd
        stack<int> st; //st me check krte rho gcd
        vector<int> ans;
        for(auto it: nums){
            ll temp = it;
            while(!st.empty() && get_gcd(st.top(),temp)!=1){
                temp = (1LL*st.top()*temp ) /get_gcd(st.top(),temp) ;
                st.pop(); //ye wala gcd dalo
            }
            st.push(temp); 
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};