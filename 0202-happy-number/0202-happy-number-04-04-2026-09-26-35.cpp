class Solution {
public:
    bool isHappy(int n) {
        //todte jao and set me store sum
        //agar sum repeat hua toh false wrna 1 aaega
        unordered_set<int> st;
        while(true){
            int sum = 0;
            while(n!=0){  //is loop me sare digit ka square sum lelo
                sum+= pow(n%10, 2);  //9^2 + 1^2 = 82
                n = n/10;  //1
            }

            if(sum==1)
                return true;
            if(st.find(sum)!= st.end())  //repeat ho rha
                return false;    
            st.insert(sum);   //82
            n = sum;  //82 -> firse ispe try kro   
        }
        return 1;
    }
};