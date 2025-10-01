class disjoint_set{
    public: 
    vector<int> parent, rank;
    disjoint_set(int n){   //constructor
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }

    int find_parent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = find_parent(parent[node]); //iska parent ko bhejo    
    }
    void union_set(int u, int v){
        int parent_u = find_parent(u);
        int parent_v = find_parent(v);

        if(parent_u == parent_v)
            return;

        if(rank[parent_u] > rank[parent_v]){
            parent[parent_v] = parent_u;
        } 
        else if(rank[parent_u] < rank[parent_v]){
            parent[parent_u] = parent_v;
        }
        else{  //dono ka rank same hai
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }   
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //lexigrophically smallest string o/p kro
        //any no of times swap kr skte given idxes ko from pairs vector
        // = lexigraphically smallest string milega from: jo idxs pair aa rhe unme kuch common hai toh same grp/set me rkho warna dusre me
        // e.g. [[0,3], [3,4], [1,2], [2,5], [2,6], [5,6]], s = "samoyed"
        // here, 0,3,4 ka parent -> 0  -> "soy"  -> iska lexigraphicaaly smallest hoga (sort) -> "osy"
        // 1,2,5,6 ka parent 1 lelo    -> "amed" ->   " " sort ->  "adem" 
        //ab rearrange krlo in dono grp me 
        int n =s.length();
        disjoint_set ds(n);
        for(auto it: pairs) {
            int idx1 = it[0];
            int idx2 = it[1];
            ds.union_set(idx1,idx2);
        }
        unordered_map<int, vector<int>> adj;
        for(int i=0;i<n;i++){
            adj[ds.find_parent(i)].push_back(i);
        }
         for (auto it : adj) {
            vector<int> indices = it.second;
            string chars = "";
            for (int idx : indices) {
                chars += s[idx];
            }
            sort(chars.begin(), chars.end());
            for (int i = 0; i < indices.size(); i++) {
                s[indices[i]] = chars[i];
            }
        }

        return s;
    }
};