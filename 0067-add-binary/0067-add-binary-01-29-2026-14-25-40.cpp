class Solution {
public:
    string addBinary(string a, string b) {
        //0 + 1 = 1 = 1 + 0
        // 0 + 0 = 1
        //1 + 1 = 10
        // 011
        // 001
        // 100  -> carry ja rha  
        // make string of equal length.
        while( a.length() > b.length() )  //append krdo -> 01, 001 ,0001
            b = '0'+b;
        while( a.length()< b.length() )
            a = '0'+a;
       
        int carry = 0;
        string ans;
    //11 // 01
        for(int i=a.size()-1;i>=0;i--){
            int sum = (a[i]-'0') + (b[i]-'0')+carry; //2
            ans = to_string(sum%2)+ ans;  //'0'
            carry = sum/2;                //1
        }
        if(carry != 0)
            ans = "1"+ans;
        return ans;
    }
};