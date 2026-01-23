class MapSum {
public:
struct trieNode{
    trieNode * children[26];
    int val_sum; //jis v curr char p ho uska val sum
};

trieNode * getTrieNode(){
    trieNode * curr = new trieNode();
    for(int i=0;i<26;i++){
        curr->children[i] = NULL;
    }
    curr->val_sum = 0;
    return curr;
}
trieNode * root = getTrieNode();
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        //insert in trie -> sare cahr pe val daldo
        trieNode * curr = root;
        for(auto it: key){
            int ch_idx = it-'a';  //b/w 0 to 25
            if(curr->children[ch_idx] == NULL)
                curr->children[ch_idx] = getTrieNode();
            curr = curr->children[ch_idx]; //curr = curr->next  
            curr->val_sum +=val;      
        }
    }
    
    int sum(string prefix) {
        //is prefix se check krlo trie me
        trieNode * curr = root;
        for(auto it: prefix){
            int ch_idx = it-'a';
            if(curr->children[ch_idx] == NULL)
                return 0;
            cout<<curr->children[ch_idx]->val_sum;
            curr = curr->children[ch_idx];    
        }
        return curr->val_sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */