class Disjoint_set{
    public: //can be accessed outside c;lass
    vector<int> parent, rank;
    Disjoint_set(int n){  //constructor
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find_parent(int node){  //ultimate parent/set of node
        if(node==parent[node])
            return node;

        return parent[node] = find_parent(parent[node]);  //parent[node] ka parent dhundhte jao and store in parent[node] 
    }
    void union_set(int u, int v){
        int u_parent = find_parent(u);
        int v_parent = find_parent(v);

        if(u_parent == v_parent)
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
bool is_similar(string &s1, string &s2){  //check 1 se jyada swap ni ho = diff = 2
    int m = s1.length();
    int diff = 0;
    for(int i=0;i<m;i++){
        if(s1[i] !=s2[i])
            diff++;
    }
    return diff == 2 || diff==0;  //2 ya 0
}
    int numSimilarGroups(vector<string>& strs) {
        //group bn rha = dsu -> starting me sb alag hai fir union, find
        //tars, rats, arts -> g1
        //star -> g2

        int n = strs.size();
        Disjoint_set ds(n);
        int grp_cnt = n; //sb single hai
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( is_similar(strs[i],strs[j]) && ds.find_parent(i) != ds.find_parent(j) ){ //alag set se hai and simmilar hai
                    ds.union_set(i,j);
                    grp_cnt--;  //same grp
                }
            }
        }
        return grp_cnt;
    }
};