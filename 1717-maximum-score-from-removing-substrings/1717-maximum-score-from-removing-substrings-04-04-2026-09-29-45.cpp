class Solution {
public:
    int maximumGain(string s, int x, int y) {
        //ek bar me dono try kiya delete krne ka -> greedy -> not maxim points
        //bcz kya pta 'ab' hatana jyada points det
        // = jo jyada points de rha pehle sirf uspe check krlo string ko

        //stack<char> st me v rkh skte -> push krte rho until st.top() == maxi[0]
        // && s[i] == maxi[1]

        int max_points = 0;
        int min_points = 0;
        string maxi,mini;

        if(x>y){
            max_points = x;
            maxi = "ab";
            min_points = y;
            mini = "ba";
        }
        else{
            max_points = y;
            maxi = "ba";
            min_points = x;
            mini = "ab";
        }
       
        int i=1;
        int ans = 0;
        while(i<s.length()){
            if(i-1>=0 && s[i]==maxi[1] && s[i-1]==maxi[0]){
                s.erase(i-1,2);
                i-=2;
                ans += max_points;
            }
            i++;
        }    

        //alag traversal for minimum points wala:
        i=1;
        while(i<s.length()){
            if(i-1>=0 && s[i]==mini[1] && s[i-1]==mini[0]){
                s.erase(i-1,2);
                i-=2;
                ans += min_points;
            }
            i++;
        }
        return ans;  
    }
};