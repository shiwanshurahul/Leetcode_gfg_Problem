class Solution {
public:  //same as word ladder 
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        //minimum mutation -> bfs
        //1 step me 1 char chnage kr skte
        //i/p str to o/p str me convert krne me steps using bank

        //sare char ('A', 'C', 'G', 'T') ek ek krke har jagah dalne ka dekho and check in bank
        //e.g i/p-> AAAACCCC -> AAAAACCC, AAAAAACC, AAAAAAAC, AAAAAAAA, CAAACCCC, ACAACCCC, AACACCCC, AAACCCCC, fir G se and then T se
        //lvl 1 -> ab jo v word inme se exists (ACAACCCC) uspe ye process repeat -> AAAACCCC, ACAAACCC, ACAAAACC, ACAAAAAC, ACAAAAAA, ..
        //lvl 2 -> repeat
        //..
        //jisko use kr chuke hai usko mark kr do visited as wapas startGene na bn jaye
        //level order traversal -> bfs
        vector<char> v = {'A', 'C', 'G', 'T'};
        queue<string> q;

        q.push(startGene);
        unordered_set<string> vis;
        vis.insert(q.front());
        int level = 0;

        while(!q.empty()){
            int n = q.size();
            while(n--){
                string str = q.front();
                if(str==endGene)
                    return level;
                q.pop();
               
                for(char ch: "ACGT"){// for(int ch=0;ch<4;ch++){  // sara char dalke check
                    for(int i=0;i<8;i++){
                        string curr = str;
                        curr[i] = ch;
                        auto it = find(bank.begin(), bank.end(), curr);
                        if(it !=bank.end() && vis.find(curr) ==vis.end() ){  //exists in bank but not in vis
                            q.push(curr);
                            vis.insert(curr);
                        }
                    }
                }
            }
            level++;
        }

        return -1;
    }
};