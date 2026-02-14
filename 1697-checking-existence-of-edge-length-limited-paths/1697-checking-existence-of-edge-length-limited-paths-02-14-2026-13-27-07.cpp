class Solution {
public:
class Disjoint_set{
    public:
    vector<int> parent;
    vector<int> rank;

    Disjoint_set(int n){  //constructor
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){ //intially sb apne paren hai
            parent[i] = i; 
        }
    }
    int find_parent(int x){
        if(x== parent[x])
            return x;
        return parent[x] = find_parent(parent[x]);    
    }
    void union_set(int u, int v){
        int u_parent = find_parent(u);
        int v_parent = find_parent(v);

        if(u_parent  == v_parent)
            return; //same set

        if(rank[u_parent] < rank[v_parent]){
            parent[u_parent] = v_parent;
        }  
        if(rank[u_parent] > rank[v_parent]){
            parent[v_parent] = u_parent;
        }    
        else{
            parent[u_parent] = v_parent;
            rank[v_parent]++;
        }
    }
};
bool dfs(int src, int dest, int limit, unordered_map<int, vector<pair<int,int>>> &adj, vector<int>&vis ){
    
    vis[src] = 1;
    if(src == dest)
        return true;

    bool ans = false;
    for(auto it: adj[src]){//{v1,w1}, {v2,w2} ->adj list me yahi hai
        int v = it.first;
        int wt = it.second;
        if( !vis[v] && wt < limit){  //strcitly less
            bool val = dfs(v,dest,limit,adj,vis);
            ans = ans || val;
        }       
    }
    return ans;
}
static bool cmp(vector<int>&a, vector<int>&b){
    return a[2] < b[2];  //in ascendin order of dis
}
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        //grap me generally sbse pehl bfs/dfs soch
        //brute forc -> dfs/bfs with considering only that path jiski dis < queries[2].  -> tle
        // agar tm queries[1] pe pahunce = true  
        //brute forc2 -> with dsu -> har queries pe components = 0 krdo and try to iterate on edgeList and reac queries[1].
        // ye v tle dega as har query pe tm compoents = 0 kr rhe

        // unordered_map<int, vector<pair<int,int>>> adj;
        // //u -> {v1,w1} , {v2,w2}, ..
        // for(auto it: edgeList){
        //     int u = it[0];
        //     int v = it[1];
        //     int wt = it[2];

        //     adj[u].push_back({v,wt});
        //     adj[v].push_back({u,wt});
        // }
        
        // vector<bool> ans;
        // for(auto it: queries){
        //     vector<int> vis(n,0); //for each query

        //     int src = it[0];
        //     int dest = it[1];
        //     int limit = it[2]; //isse stritly less rkhn hai
        //     bool val = dfs(src,dest,limit,adj,vis);
        //     ans.push_back(val);
        // }     
        // return ans;  // -> tle 

        //m2:
        //dsu + sort queries w.r.t q[2] = ab sare queries pe 
        // components = 0 krne ki no need = bar bar scrtch se
        // union ni krna pdega
        //keep track of idx -> as ans w.r.t idx chahiy
        //edgesList v sort krlo similarly on wt
        //as smaller path/edge hai toh large walo ko benefit mileg

        Disjoint_set dsu(n);
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i); //idx v daldo
        }
        sort(edgeList.begin(), edgeList.end(),cmp);
        sort(queries.begin(), queries.end(),cmp);

        vector<bool> ans(queries.size(),0);
        int j=0;
        for(auto it: queries){

            int u = it[0];
            int v = it[1];
            int limit = it[2]; //isse stritly less rkhn hai
            int idx = it[3];
            while(j<edgeList.size() && edgeList[j][2] < limit){
                dsu.union_set(edgeList[j][0], edgeList[j][1]);
                j++;
            } //j ka loop se bahar ane ka 2 reason:
            //1. sare edgeList bana diye
            //2. j pe edgeList[j][2] > limit hai

            if(dsu.find_parent(u) == dsu.find_parent(v))
                ans[idx] = true; //connected hai
            else
                ans[idx] = false;
        } 
        return ans;    
    }
};