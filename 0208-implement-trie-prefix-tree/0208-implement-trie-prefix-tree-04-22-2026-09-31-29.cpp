class Trie {
public:
struct trieNode {  //can be used as datatype
    bool is_end_of_word;
    trieNode * children[26];  //will store pointer to next trieNode in respectiv idx
};

trieNode * create_node(){
    trieNode * node = new trieNode;   //will hav 2 fields
    node->is_end_of_word = false;

    for(int i=0;i<26;i++){
        node->children[i] = NULL;
    }
    return node;
}

  trieNode * root; 

    Trie() {
        root = create_node();
        
    }
    
    void insert(string word) {
        trieNode *curr = root; 
        for(auto it: word){
            int ch_idx = it-'a';  //or idx
            if(curr->children[ch_idx] == NULL)  //null hai us idx pe mtlab no pointer to any trieNode
                curr->children[ch_idx] = create_node();

            curr = curr->children[ch_idx];   //curr now points to the trieNode jiski pointer tmne store kiya i idx pe   
        }
        //curr is at end of word
        curr->is_end_of_word = true;
    }
    
    bool search(string word) {
        trieNode* curr = root;

        for(auto it: word){
            int ch_idx= it-'a';
            
            if(curr->children[ch_idx] ==NULL) //yahan p pointer hona chaiy tha
                return false; 
            curr = curr->children[ch_idx];  //curr ko jo index mil rha 'i' usme jo pointer hai uspe point  
        }
        if(curr != NULL && curr->is_end_of_word == true)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
       trieNode* curr = root;
       int len_flag = 0;
       for(auto it: prefix){
           int i = it-'a';
           len_flag++;
           if(curr->children[i] ==NULL)
            return false;
            curr = curr->children[i];  //curr = curr->next jaisa
       }
        if(curr !=NULL && len_flag == prefix.length())
        return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */