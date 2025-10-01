class DisjointSet  {
    vector<int> parent, rank;
public:   
    DisjointSet(int n){  //constructor
        parent.resize(n,0);
        rank.resize(n,0); 
        for(int i=0;i<n;i++){
            parent[i] = i;    //initially sb parent hai apne
        }
    }
    int find_parent(int node) {  // ultimate set/parent pta kro
        if(node==parent[node])   //apna parent
            return node;   //is set ka ye hi parent/representative hai
        
        return parent[node] = find_parent(parent[node]);  //parent[node] ka parent dhundhte jao and store in parent[i]
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
    bool equationsPossible(vector<string>& equations) {
        //2nd char is always '=', 0th and 3rd are alphabets
        //== pe union krdo and != pe find krlo if parent same toh return false
        DisjointSet ds(26);
        for(auto it: equations){
            if(it[1]=='='){  //pehle sbka union krdo
                cout<<it[1]<<it[0]<<endl;
                ds.union_set(it[0]-'a',it[3]-'a');
            }
        }    
            //ab ! wale pe check
            for(auto it: equations){
                if(it[1]=='!'){
                    int parent_u = ds.find_parent(it[0]-'a');
                    int parent_v = ds.find_parent(it[3]-'a');
                    if(parent_u==parent_v)  //same parent ni hona tha
                        return false;
            }
        }
        return true;
    }
};