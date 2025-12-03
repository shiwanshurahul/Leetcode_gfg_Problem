class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
     int n =gas.size();
     int total_kamai = accumulate(gas.begin(),gas.end(),0);
     int total_kharcha =accumulate(cost.begin(),cost.end(),
     0);
     if(total_kamai<total_kharcha)
     return -1;
int res_index=0, total =0;
for(int i=0;i<n;i++){
    total += gas[i] -cost[i];
    if(total<0){
    res_index =i+1;
    total =0;
    }
}
return res_index;
    }
};