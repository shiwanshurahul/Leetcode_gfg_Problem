class Solution {
public:
    string frequencySort(string s) {
      priority_queue<pair<int,char>> pq;
      unordered_map<char,int> mp;
      string str="";
            for(auto it:s){
                mp[it]++;
            }
            for(auto it= mp.begin();it!=mp.end();it++){
                pq.push({it->second, it->first });
            }
            while(pq.size()){
                int k =pq.top().first;
                int l =pq.top().second;
                for(int i=0;i<k;i++){
                    str.push_back(l);
                }
                pq.pop();
            }
            return str;
    }
};