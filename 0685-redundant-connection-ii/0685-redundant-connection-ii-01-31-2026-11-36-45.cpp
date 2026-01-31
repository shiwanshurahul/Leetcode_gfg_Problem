class Solution {
public:
class Disjoint_set{
    public:
        vector<int> rank;
        vector<int> parent;
        Disjoint_set(int n){  //constructor
            parent.resize(n+1);
            rank.resize(n+1,1);
            for(int i=1;i<n+1;i++){
                parent[i] = i;  //initially
            }
        }
        int find_parent(int x){
            if(x == parent[x])
                return x;
            return parent[x] = find_parent(parent[x]);  //path compression   
        }
        bool union_set(int u, int v){
            int u_parent = find_parent(u);
            int v_parent = find_parent(v);

            if(u_parent == v_parent)
                return true;  //already same set hai

            if(rank[u_parent] > rank[v_parent]){
                parent[v_parent] = u_parent;
            }    
            else if(rank[u_parent] < rank[v_parent]){
                parent[u_parent] = v_parent;
            }
            else{  //dono ka same rank hai
                parent[u_parent] = v_parent;
                rank[v_parent]++;
            }  
            return false;    
        }
};

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        //dsu primarily used for detecting cycles in undirected graphs, not directed graphs, idhar directed edge hai toh kuch dfs wagera lgana pdega.
        
        //one node can have only one par i.e 1 indegree
        //max 1 node ki indegree 2 ho skti
        //1 indegree hai and cycle hai toh return cycle form krne wala edge
        //agar 2 indegree + cycle dono hai toh return cycle form krne wala
        //warna 2 indegree hai sorf toh return 2nd parent jo hai

        // ao,there are three cases
        // 1. 2 par -> return 2nd parent 
        // 2. cycle present -> but how to check in this directed grap
        // 3. 2 par + cycle -> return jis node se cycle hai

        // there is only one whose can max of 2 indegee, i.e kisi ek ke pas hi 2 indegree (mtlb do par) ho skte
        // agr kisi ki bhi indegree 2 nhi hh toh hm dsu ki help se cycle check krenge (works only for this proble) or last edge jisse cycle ho rha hoga use hta denge
        // dsu se directed ka cycle pta nhi lga skte, pr agr pta ho ki kisi ki bhi 2 parent nhi hai toh find kr skte h; only isi case me
        // agr jaise 2 parent h kisi me toh hme vo edges mil jayegi unme se ek answer hoga toh hm last vali ko htakar dekhenge
        //  ki hatane ke bad bhi cycle rh jata hh toh hm fisrt edge answer ho jayega vrna second; 

        int n = edges.size();
        vector<int> indegree(n+1,-1);
        Disjoint_set dsu(n);
        int b1 =-1;     // we store two index which has two parent,
        int b2 =-1;     //such edges if present

         //first step is find the node with indegree 2
        for (int i=0;i<n;i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if(indegree[v] == -1) {
                indegree[v] = i;
            }else{   //-1 ni hai = (already 1 tha) = 2 par hai
                b1 = i;
                b2 = indegree[v];
            }
        }

        //second step is to detect cycles and remove the node which is not blacklisted
        for (int i=0;i<n;i++) {
            if(i == b1)
                continue;
            int u = edges[i][0];
            int v = edges[i][1];
            if(dsu.union_set(u,v)) { //cycle detected, so could be c2 or c3
                if(b1 == -1)
                    return edges[i]; //c2
                else
                    return edges[b2]; //c3
            }
        }
        
        // no cycle is detected, so return latest element in array, so bl1
        return edges[b1]; // c 1

        // Disjoint_set dsu(n);
        // for(auto it: edges){
        //     int u = it[0];
        //     int v = it[1];
        //     int u_parent = dsu.find_parent(u);
        //     int v_parent = dsu.find_parent(v);
        //     if(u_parent != v_parent)  //same set me dalo
        //         dsu.union_set(u,v);
        //     else //already same set, cycle
        //         return {u,v};    
        // }
        // return {};
    }
}; 
         