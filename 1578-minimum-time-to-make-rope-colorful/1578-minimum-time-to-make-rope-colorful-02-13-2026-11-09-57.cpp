class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        //a a a a a a a -> all same colr
        //1 2 1 5 1 1 6
        //b
        //    b
        //  b
        //        b
        //           b 
        //      5 
        // = 1 + 1 + 2 + 1 + 1 + 5 = 11
        //prev max of same color ka track rkho
        //chote val/time wale ko burst on duplicat
        //i.e time -> min(prev,curr)
        // a a b a a 
        // 1 2 3 4 1
        int n = colors.size();
        int sum = 0;
        int prev_max = 0;
       
        for(int i=0;i<n;i++){
            if(i>0 && colors[i] !=colors[i-1])
                prev_max = 0; //diff color = prev-max is 0

            int curr = neededTime[i];
            sum += min(curr,prev_max); 
            prev_max = max(prev_max,curr); //curr ya prev wala mx
        }
        return sum;
    //i = 0             1              2                     
    } //s=0,prev=1; s=1,prev=2; prev=0,s=1,prev=3; 
}; // 3                     4
  // prev=0,s=1,prev=4     s=1+2,prev=4  = 2