class Solution {
public:
typedef long long ll;
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        //sort kro ya max heap
        priority_queue<int> pq;
        ll ans = 0;
        for(auto it: happiness){
            pq.push(it);
        }
        int cnt = 0;
        while(k !=0){
            ans+= max(pq.top()-cnt, 0);
            pq.pop();cnt++;
            k--;
        }
        return ans;
        
    }
};