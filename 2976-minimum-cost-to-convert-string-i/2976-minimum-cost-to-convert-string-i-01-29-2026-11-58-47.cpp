class Solution {
public:
typedef long long ll;
void floyd_warshall(vector<vector<ll>> &adj_matrix, vector<char>& original, vector<char>&changed, vector<int>&cost){
    int n = original.size();  //fill the adj_matrix
    for(int i=0;i<n;i++){
        int s = original[i]-'a';
        int t = changed[i] -'a';
        adj_matrix[s][t] = min(adj_matrix[s][t],(long long)cost[i]);
    }

    //apply floyd -warshall
    for(int via=0;via<26;via++){
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){  //i se j jao through via/k
                adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][via] + adj_matrix[via][j]);
            }
        }
    }
}
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        //source se target banana hai with d help of original and changed
        //e.g.    source = "abcd"
        //  target = "acbe"
        //  orig = ["a", "b", "c", "c", "e","d"]
        //  chna = ["b", "c", "b", "e", "b", "e"] 
        //  cost = [ 2    5    5    1    2    20]
        //               +5    +5            +20 = 30  (a,b->c,c->b,d->e)  
        //               +5        +1   +2   +20 = 28 =min(a,b->c,c->e,e->b,d->e)

        //graph me shortest path algo -> djiktra, floyd
        // Dijkstra finds the shortest path from a single source to all other nodes (great for sparse graphs, needs non-negative weights), while Floyd-Warshall finds the shortest path between all pairs of nodes (good for dense graphs, handles negative weights but not negative cycles)
        // = idhar floyd lagao -> via through jate hai -> matrix bharte
        int n = source.length();
        ll ans = 0;
        vector<vector<ll>> adj_matrix(26,vector<ll>(26, 1e15));
        floyd_warshall(adj_matrix,original,changed,cost);

        for(int i=0;i<n;i++){
            if(source[i] == target[i]) //no conversion req
                continue;    
            //else    
            if(adj_matrix[source[i]-'a'][target[i]-'a'] == 1e15)
                return -1;  //not possibl   
            ans+= adj_matrix[source[i]-'a'][target[i]-'a'];
        }
        return ans;
        
    }   
};