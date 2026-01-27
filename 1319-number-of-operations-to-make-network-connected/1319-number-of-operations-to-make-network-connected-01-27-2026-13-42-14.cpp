class Solution {
public:
class DisjointSet{
    public:
        vector<int> parent;
        vector<int> rank;
        DisjointSet(int n){   //constructor
            parent.resize(n);
            rank.resize(n,0);
            for(int i=0;i<n;i++){  //apne parent suru me
                parent[i] = i;
            }
        }
        int find_parent(int x){
            if(x==parent[x])
                return x;
            return parent[x] = find_parent(parent[x]);    
        }
        void union_set(int u, int v){
            int parent_u = find_parent(u);
            int parent_v = find_parent(v);

            if(parent_u == parent_v)
                return;

            if(rank[parent_u] < rank[parent_v]){
                parent[parent_u] = parent_v;
            }
            else if(rank[parent_u] > rank[parent_v]){
                parent[parent_v] = parent_u;
            }
            else{  //dono ka rank equal hai
                parent[parent_u] = parent_v;
                rank[parent_v]++;
            }    
        }
};
    int makeConnected(int n, vector<vector<int>>& connections) {
        //dsu
        DisjointSet ds(n);
        
        if(connections.size() < n-1)
            return -1;
        int components = n; //sb individual initally    

        for(auto it: connections){
            int u_parent = ds.find_parent(it[0]);
            int v_parent = ds.find_parent(it[1]);

            if(u_parent != v_parent){
                ds.union_set(u_parent, v_parent);
                components--;
            }
        }
        return components-1;    

    }
};