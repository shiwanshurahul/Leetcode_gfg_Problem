class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        //3rd typ slidin windo -> i se j tk me valid rkho warna slide window 
        //ith ko jth me convert kr skt usin |s[i] - t[i]|
        int i=0,j=0;
        int ans=0, curr_cost=0;

        while(j<s.length()){
            curr_cost +=abs(s[j]-t[j]);

            while(curr_cost > maxCost){   
                curr_cost = curr_cost- abs(s[i]-t[i]); //remove calc for i
                i++;   //slide windo
            }
            ans = max(ans, j-i+1);   //har br
            j++;
        }
        return ans;
    }
};