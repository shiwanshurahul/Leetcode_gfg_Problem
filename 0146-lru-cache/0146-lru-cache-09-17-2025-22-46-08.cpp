class LRUCache {
public:
//capacity is the default size initialized
//put krte waqt agar size== capacity hai toh lru-> sbse purane wale ko delete and this key is fresh
//get ho rha key toh ab wo lru ni hai -> uska timestamp update krdo -> delete krke push_back
//vector<pair<int,int>> lelo -> push_back for fresh, erase from front
// vector<pair<int,int>> v;  -> tle as traversal o(n) then erase v o(n) = linked_list use krlo and to get val use map 
int n;
list<int> ll;  //key
map<int, pair<list<int>:: iterator, int>>mp;  //address off ll node, value

void make_recently_used(int key){
    ll.erase(mp[key].first);  //purana address
    ll.push_front(key);

    mp[key].first = ll.begin(); //new address    
}
    LRUCache(int capacity) {
      n = capacity;  
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        //else exists in map -> make it recently used = front pe lao and pehle wala erase krdo
        make_recently_used(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){ //exists = update the value and make recent
            mp[key].second = value;  //update val in map
            make_recently_used(key);
        }
        else {   //doesn't exists
            ll.push_front(key);  //front pe
            mp[key] = {ll.begin(), value};
            n--;  //ek space used
        }

        if(n<0){  //back se remove from ll and map
            int key_lru = ll.back();
            mp.erase(key_lru);
            ll.pop_back();
            n++;
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */