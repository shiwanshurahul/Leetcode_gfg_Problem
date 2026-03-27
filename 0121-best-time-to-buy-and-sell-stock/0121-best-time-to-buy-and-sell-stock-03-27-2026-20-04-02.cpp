class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 1e9;  //ispe kharid
        int today_profit =0;  //dail ka profit chk kro
        
        for(int i=0;i<prices.size();i++){
            if(mini>prices[i])
                mini = prices[i];  //7,1
            today_profit = max(today_profit,prices[i]-mini);  //0,0,4,2,5,5
        }
        return today_profit;
    }
};