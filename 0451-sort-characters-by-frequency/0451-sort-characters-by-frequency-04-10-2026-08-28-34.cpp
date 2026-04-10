class Solution {
public:
typedef pair<int,int> p;
    string frequencySort(string s) {
        priority_queue<p> pq;   //mx heap
        unordered_map<char,int> mp;
        string ans="";
        
        for(auto it: s){  //each char ka freq stor
            mp[it]++;     //'e'->2, 't'->1, 'r'->1
        }

        // for(auto it = mp.begin();it!=mp.end();it++){
        //     pq.push({it->second, it->first });  //{freq, char}
        // }   //e.g. {2,e} -> freq ke hisb se sort rheg

        //or
        for(auto it: mp){
            pq.push({it.second, it.first});
        }

        while(pq.size()){
            int cnt = pq.top().first;
            int ch = pq.top().second;
            for(int i=0;i<cnt;i++){
                ans.push_back(ch);
            }   
            pq.pop();
        }
        return ans;
    }
};