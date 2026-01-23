class Solution {
public:
struct trieNode{
    trieNode * children[26];
    int cnt_prefix = 0;   //cnt khud tak ka as prefix
};

trieNode * create_trieNode(){
    trieNode * curr = new trieNode();
    for(int i=0;i<26;i++){
        curr->children[i] = NULL;
    }
    curr->cnt_prefix =0;
    return curr;
}

void insert_in_trie(string word, trieNode * root){
    trieNode * curr = root;
    for(auto it: word){
        int ch_idx = it-'a';
        if(curr->children[ch_idx] ==NULL)
         curr->children[ch_idx] = create_trieNode();
         curr->children[ch_idx]->cnt_prefix++;
          curr = curr->children[ch_idx];
    }
}

int search_in_trie(string &word, trieNode * root){
    int score=0;
    trieNode * curr = root;
    for(auto it: word){
        int ch_idx = it- 'a';
        if(curr->children[ch_idx] ==NULL)
           return score;
        score += curr->children[ch_idx]->cnt_prefix;   
        curr = curr->children[ch_idx];
    }
    return score;
}

    vector<int> sumPrefixScores(vector<string>& words) {
        //good for understanding
        trieNode * root = create_trieNode();
        for(auto &it: words){
            insert_in_trie(it, root);
        }
        vector<int> ans;
        for(auto &it: words){
           ans.push_back(search_in_trie(it, root));
          
        }
        return ans;
    }
};