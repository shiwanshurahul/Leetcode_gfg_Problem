class Solution {
public:
int solve(string &str,int s, int e, int k){
    if(e-s <k)
        return 0;
    vector<int> freq(26,0); 
    for(int i=s;i<e;i++){
        freq[str[i]-'a']++;
    } //sare char ka cnt

    for(int i=s;i<e;i++){
        if(freq[str[i]-'a'] < k){
            int j = i+1;  //iske left and right dono pe call
            while(j<e && freq[str[j]-'a'] < k){
                j++;
            }
            return max(solve(str,s,i,k), solve(str,j,e,k));
        }
    }
    return e-s;
}
    int longestSubstring(string s, int k) {
        // sare elements >=k
        // = f a character appears less than k times in a substring,
//then that character can never be part of a valid answer
        //store the count of every character
        // Then after this we will find the first character whose frequency is less than k, certainly this characher will not be included in the substring. here, we will divide out string int two substring about this character -> Divide & Conquer strategy.
// Then we will call the same function on left and right substrings and return the maximum of these two values.
       return solve(s,0,s.length(),k);
    }
};