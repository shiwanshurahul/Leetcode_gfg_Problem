class DSU{
    public:
        vector<int> parent;
        vector<int> rank; //size se v kr skte
        int components = 0;
        DSU(int n){  //constructor
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i] = i; //initally sb apne parent hai
            }
            components = n; //initally sb individul componen hai of that obj
        }

        int find_parent(int x){
            if(x == parent[x])
                return x;
            return parent[x] = find_parent(parent[x]);    
        }
        void union_set(int u,int v){
            int u_parent = find_parent(u);
            int v_parent = find_parent(v);

            if(u_parent == v_parent)
                return;

            if(rank[u_parent] < rank[v_parent]){
                parent[u_parent] = v_parent;
            }
            else if(rank[u_parent] > rank[v_parent]){
                parent[v_parent] = u_parent;
            }
            else{  //dono ka same rank hai
                parent[v_parent] = u_parent;
                rank[u_parent]++;
            }
            components--;  //us obj var ka component-- 
        }
};
class Solution {
public:
static bool cmp(vector<int> &a, vector<int> & b){
    return a[0] > b[0]; //type-3 wale in descendin 
}
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        //undirected hai grap
        //dsu -> generally no adj list neede
        //type 3 is good for both = dono can travrse using this
        // while 1 for Alice and 2 for Bob only
        // = sort the edges by type 3
        //when Alice and Bob dono ka component cnt 1 ho toh return edge_cnt
        //total no of edges - edges used   
        sort(edges.begin(), edges.end(),cmp);

        DSU Alice_obj(n);  //dono ka individua obj
        DSU Bob_obj(n);

        int edge_cnt = 0;
        for(auto it: edges){
            int type = it[0];
            int u = it[1];
            int v = it[2]; 
        
            if(type==3){  //both can traverse
                bool edge_added = 0;

                if(Alice_obj.find_parent(u) != Alice_obj.find_parent(v)){
                    Alice_obj.union_set(u,v);
                    edge_added = 1;
                }
                if(Bob_obj.find_parent(u) != Bob_obj.find_parent(v)){
                    Bob_obj.union_set(u,v);
                    edge_added = 1;
                }
                if(edge_added)
                    edge_cnt++;
            }
            else if(type==2){  //only Bob can traverse
                if(Bob_obj.find_parent(u) != Bob_obj.find_parent(v)){
                    Bob_obj.union_set(u,v);
                    edge_cnt++;
                }
            }
            else if(type==1){  //only Alice can travers
                if(Alice_obj.find_parent(u) !=Alice_obj.find_parent(v)){
                    Alice_obj.union_set(u,v);
                    edge_cnt++;
                }
            }
       }
        if(Alice_obj.components == 1 && Bob_obj.components == 1)
            return edges.size() - edge_cnt++;

        return -1;    
    }
};