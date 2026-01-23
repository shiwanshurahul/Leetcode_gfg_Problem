class Solution {
public:
 static bool cmp(string& a,string & b){  //e.g. a ="9", b="34"
    return a+b >b+a ;  //"934" > "349" -> bda pehle
 }
    string largestNumber(vector<int>& nums) {
        vector<string> str;
        for(auto it: nums){
            str.push_back(to_string(it));
        }
        //str = "10", "2"
        sort(str.begin(),str.end(),cmp);
        if(str[0]=="0")
            return "0";
        string ans ="";
        for(auto it: str){
            ans+=it;
        }
        return ans;
    }  //Compare two numbers a and b by comparing strings:
       // if (a + b) > (b + a) then
       // a should come before b
};