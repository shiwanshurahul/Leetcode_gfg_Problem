class DisjointSet  {
    vector<int> parent;
public:   
    DisjointSet(int n){  //constructor
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find_parent(int node) {  // ultimate set/parent pta kro
        if(node==parent[node])   //apna parent
            return node;   //is set ka ye hi parent/representative hai
        
        return find_parent(parent[node]);   //parent[node] ka parent dhundhte jao 
    }

    void union_set(int u, int v) { //utlimate parent/set to which u belongs,
                                 // utlim. parent to which v belongs me merge  
        int u_parent = find_parent(u);
        int v_parent = find_parent(v);
        
        if(u_parent != v_parent)   //warna already same set me hai
            parent[u_parent] = v_parent;  //u ko parent bna rhe v ka 
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        //2nd char is always '=', 0th and 3rd are alphabets
        DisjointSet ds(26);
        for(auto it: equations){
            if(it[1]=='='){
                ds.union_set(it[0]-'a',it[3]-'a');
            }
            else if(it[1]=='!'){
                int parent_u = ds.find_parent(it[0]-'a');
                int parent_v = ds.find_parent(it[3]-'a');
                if(parent_u==parent_v)
                    return false;
            }
        }
        return true;
    }
};