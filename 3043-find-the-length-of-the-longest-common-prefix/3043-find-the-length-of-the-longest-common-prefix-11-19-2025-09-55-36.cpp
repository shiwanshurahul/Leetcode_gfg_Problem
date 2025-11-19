class Solution {
public:
struct trieNode {
    trieNode * children[10]; //0 -9 -> pointer store krte
};

trieNode * create_trieNode(){
    trieNode * temp = new trieNode();
    for(int i=0;i<10;i++){
        temp->children[i] = NULL;
    }
    return temp;    
}

void insert_in_trieNode(int num, trieNode * root){  //traditional insert in trie
        string word = to_string(num);  //"1" "10" "100"
        trieNode * curr = root;
        for(auto it: word){  //1    1 0    1 0 0 -> ek ek char krke
            int ch_idx = it -'0';
            if(curr->children[ch_idx]==NULL)
                curr->children[ch_idx] = create_trieNode();
            curr = curr->children[ch_idx];  //curr = curr->next
        }
}

int search_in_trie(int num, trieNode * root){  //search kitna len tak milta
    trieNode * curr = root;
    string word = to_string(num);  //"1000"
    int len=0;
    for(auto it: word){  // 1 0 0 0
        int ch_idx = it- '0';
        if(curr->children[ch_idx] ==NULL)
          return len;

        len++; // "100" -> 3 len
        curr = curr->children[ch_idx];
    }
        return len; //1 0 0 tak gya = 3
}

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //simple trie
        trieNode * root = create_trieNode();
        
        //insert arr1
        for(auto it: arr1){
            insert_in_trieNode(it, root);
        }

        int ans=0;
        //search arr2 in trieNode
        for(auto it: arr2){
            ans = max(ans, search_in_trie(it, root));  //as int hi pass kr rhe
        }
        return ans;
    }
};