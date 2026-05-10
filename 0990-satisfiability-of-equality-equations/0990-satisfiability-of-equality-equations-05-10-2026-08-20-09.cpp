class DisjointSet  {
    vector<int> parent, rank;
public:   
    DisjointSet(int n){  //constructr
        parent.resize(n,0);
        rank.resize(n,0); 
        for(int i=0;i<n;i++){
            parent[i] = i;    //initialy sb paret hai apne
        }
    }
    int find_parent(int node) {  // ultimat set/parent pta kro
        if(node==parent[node])   //apn parent
            return node;   //is set ka ye ha paret/reprstative
        return parent[node] = find_parent(parent[node]);  //parent[node] ka parent dhundte jao and store in parent[i]
    }  //path compressin

    void union_set(int u, int v) { 
                                
        int u_parent = find_parent(u);  //utlimate parent/set to which u belongs, 
        int v_parent = find_parent(v);   // utlim. parent to which v belongs me merge  
        
        if(u_parent ==v_parent)
            return;
        if(rank[u_parent] > rank[v_parent]){   
            parent[v_parent] = u_parent;  //jiska rank jyada wo parent
        }
        else if(rank[u_parent] < rank[v_parent]){
           parent[u_parent] = v_parent;
        }
        else{
            parent[u_parent] = v_parent; //kisi ko v ban do
            rank[v_parent]++;
        }
    }    
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        //2nd char is always '=', 0th and 3rd are alphabets
        //== pe union krdo and != pe find krlo if parent same toh retur false
        //dsu me generaly don't need to make adj list
        DisjointSet ds(26);
        for(auto it: equations){
            if(it[1]=='='){  //pehl sbka union krdo
                ds.union_set(it[0]-'a',it[3]-'a');
            }
        }    
            //ab ! wale pe check
            for(auto it: equations){
                if(it[1]=='!'){
                    int parent_u = ds.find_parent(it[0]-'a');
                    int parent_v = ds.find_parent(it[3]-'a');
                    if(parent_u==parent_v)  //same paret ni 
                        return false;       // hona tha
            }
        }
        return true;
    }
};