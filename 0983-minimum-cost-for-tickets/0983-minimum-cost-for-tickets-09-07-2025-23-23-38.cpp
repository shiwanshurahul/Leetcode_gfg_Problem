class Solution {
public:
int solve(vector<int> &days, vector<int>& costs, int i){
    if(i>=days.size() )
        return 0;

    int one_day = costs[0] + solve(days,costs,i+1);
    
    int j = 0;  
    int max_7_day = days[i]+7;
    while(i+j <days.size() && max_7_day > days[i+j]){  //11>4, 11>6, 11>7, 11>8
        j++;             //4
    }
    int seven_days = costs[1] + solve(days,costs,i+j);   //7 din bad wale pe aao -> j v pass kr skte agar initially j ko i ke equal kroge toh
    
    int k = i;
    int max_30_days = days[i] + 30;
    while(i+k< days.size() && max_30_days > days[i+k]){
        k++;
    }
    int one_month = costs[2] + solve(days,costs,i+k); //30 din bad wale pe aao
    
    return min({one_day, seven_days, one_month});  

}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //min amount
        //costs array 3 size ka rhega
        //teeno cases explore krlo
        return solve(days,costs,0);
    
    }
};