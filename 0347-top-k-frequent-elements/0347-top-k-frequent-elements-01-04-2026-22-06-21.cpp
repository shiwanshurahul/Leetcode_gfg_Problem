class Solution {
public:
typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<p, vector<p> , greater<p>> pq;
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        vector<int> ans;
        //iterate on mp:
        for(auto i =mp.begin();i!=mp.end();i++){
            pq.push({i->second, i->first}); // (cnt,elem)
            if(pq.size()>k)
                pq.pop();
        }  //small freq wale pop
        while(pq.size()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;    
    }
    };