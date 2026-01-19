class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
      //fixed size = windown maintained rkho jb j-i+1 = minutes
      //seedha max nikal ke from cust ni lga skte as what if wo tb grumpy ni ho
      //last me grumpy window ka max sum + normal customer statisfied ka sum ko return
      //grumpy = 1 
      // cust =  [1,0,1,2,1,1,7,5]
      // grumpy= [0,1,0,1,0,1,0,1]
      //har grumpy window==minutes pe lga do and check krte rho max and slidw window  
        int n = customers.size();
        int i=0,j=0;
        int ans = 0,sum=0;

        while(j<n){
            if(grumpy[i]==1)
                sum += customers[j];
            if(j-i+1<minutes){
                j++;
            }
            else if(j-i+1 == minutes){ //maintained rkho window size
                ans = max(ans,sum);    //calc ans
                if(grumpy[i]==1)       //remove caln for i
                    sum -= customers[i]; 
                i++;                   //slide the window 
                j++;    
            }   
        }
        for(auto i=0;i<n;i++){
            if(grumpy[i]==0)  //not grumpy = cust satisfied
                ans += customers[i];
        }
        return ans;

    }
};