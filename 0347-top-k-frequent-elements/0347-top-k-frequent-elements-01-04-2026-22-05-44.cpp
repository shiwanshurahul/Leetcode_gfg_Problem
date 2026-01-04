class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    unordered_map<int,int> mp;
    for(auto it: nums){
        mp[it]++;
    }
    vector<int> ans;
    for(auto i=mp.begin();i!=mp.end();i++){
        pq.push({i->second,i->first});
        if(pq.size()>k)
        pq.pop();
    }
    while(pq.size()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;    
    }
};