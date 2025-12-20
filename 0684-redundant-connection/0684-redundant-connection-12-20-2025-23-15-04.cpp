class Solution {
public:
class DisjointSet{
    vector<int> parent;
    vector<int> rank;
    public:
    DisjointSet(int n){  //constructor
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<n+1;i++){   //initially sb spne parent hai
            parent[i] = i;
        }
    }
    int find_parent(int x){
        if(x==parent[x])
            return x;
        return parent[x] = find_parent(parent[x]);    
    }
    void union_set(int u, int v){
        int u_parent = find_parent(u);
        int v_parent = find_parent(v);

        if(u_parent == v_parent)
            return;
        else if(rank[u_parent] < rank[v_parent]){
            parent[u_parent] = v_parent;
        }
        else if(rank[u_parent] > rank[v_parent]){
            parent[v_parent] = u_parent;
        }
        else{   //same rank
            parent[v_parent] = u_parent;
            rank[u_parent]++;
        }
    }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        ///last wala edge remove jisse cycle hat jaye and tree bn jaye
        //jab v do ka same parent ho wo return
        int n = edges.size();
        DisjointSet ds(n);

        for(auto it: edges){
            int u_parent = ds.find_parent(it[0]);
            int v_parent = ds.find_parent(it[1]);
            if(u_parent != v_parent)
                ds.union_set(u_parent,v_parent);
            else
                return {it}; //cycle hai    
        }
        return {};
    }
};