class Disjointset{
    vector<int> parent, rank;
    public:
    Disjointset(int n){  //constructor
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find_parent(int node) {  // ultimate set/parent pta kro
        if(node==parent[node])   //apna parent
            return node;   //is set ka ye hi parent/representative hai
        
        return parent[node] = find_parent(parent[node]);  //parent[node] ka parent dhundhte jao and store in parent[node]
    }  //path compression

    void union_set(int u, int v) { 
                                
        int u_parent = find_parent(u);  //utlimate parent/set to which u belongs, 
        int v_parent = find_parent(v);   // utlim. parent to which v belongs me merge  
        
        if(u_parent ==v_parent)
            return;
        if(rank[u_parent] > rank[v_parent]){   
            parent[v_parent] = u_parent;  //jiska rank jyada wo parent
            rank[u_parent]++;
        }
        else if(rank[u_parent] < rank[v_parent]){
            parent[u_parent] = v_parent;
            rank[v_parent]++;
        }
        else {
            parent[u_parent] = v_parent; //kisi ko v bana do
            rank[v_parent]++;
        }
    }    
};
class Solution {
public:
static bool cmp(vector<int> &a, vector<int>&b){
    return a[2] < b[2];
}
int kruskal(vector<vector<int>>& edges_wt, int V){
    Disjointset ds(V);
    int sum =0;
    for(auto it: edges_wt){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(ds.find_parent(u) != ds.find_parent(v)){
            ds.union_set(u,v); 
            sum+= wt;
        } //else me cycle hai -> can't have in mst
    }
    return sum;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        //kruskal's -> sort w.r.t wt
        // {u1,v1, wt1} is format me convert and sbka sum lo if not in (same grp/connected/cycle)
        int V = points.size();
        vector<vector<int>> edges_wt;
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dis = abs(x1-x2) + abs(y1-y2);
                edges_wt.push_back({i,j,dis});
            }
        }
        sort(edges_wt.begin(), edges_wt.end(), cmp);
        return kruskal(edges_wt, V);
        
    }
};