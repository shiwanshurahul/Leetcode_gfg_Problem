class LRUCache {
public:

list<int> l;
int cap;
int siz;
unordered_map<int,int> mp;
unordered_map<int,list<int> :: iterator > addres;

    LRUCache(int capacity) {
     cap = capacity;   
     siz =0;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        return -1;

        list<int> :: iterator it =addres[key];
        l.erase(it);
        addres.erase(key);
        l.push_front(key);
        addres[key] =l.begin();
        return mp[key];
    }
    
    void put(int key, int value) {
//         if(mp.size()>x){
//      //hatao lru ko 
// lru hatane ke liye data ko sort krke rkho in order of recent uses
//         }

        if(mp.find(key)!=mp.end()){
            l.erase(addres[key]);
            addres.erase(key);
            mp.erase(key);
            siz--;
        }
        if(siz==cap){ //remove lru
           int k =l.back();
           l.pop_back();
           addres.erase(k);
           mp.erase(k);
           siz--;
           }
              siz++;
        l.push_front(key);
        addres[key] =l.begin();
        mp[key] =value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */