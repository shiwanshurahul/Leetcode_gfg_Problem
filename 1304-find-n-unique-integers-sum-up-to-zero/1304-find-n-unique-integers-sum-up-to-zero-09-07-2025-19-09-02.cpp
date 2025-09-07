class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1)
            return {0};

        int sum = 0;
        int i = 1;
        vector<int> v;
         while(n>1){
            v.push_back(i);
            sum+= i;
            i++;n--;
         }
         v.push_back(-sum);
         return v;    
    }
};