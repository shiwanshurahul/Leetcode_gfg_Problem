class Solution {
public:
char dfs(unordered_map<char, vector<char>> &adj, char ch, vector<int>& vis){
    vis[ch-'a'] = 1;
    char min_char = ch;  //manlo

    for(auto it: adj[ch]){
        if(vis[it-'a']==0) //unvisted
           min_char = min(min_char,dfs(adj,it,vis));
    }
    return min_char;
}
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // parker
        // morris -> equivalent string
        // baseStr ka lexicographically smallest string nikalo
        // = parser
        // (p->m) ->min = m
        // (a->o) -> min = a
        // (r->r), (r->k), (r->s) -> min = k
        // (s->r), (r->r), (r->k), (r->s) -> min = k
        // (e->i) -> min = e
        // (r->r), (r->k), (r->s) -> min = k
        // = makkek  

        //adj list banao is mapping ka: 
        // p->m, m->p, a->o, r->r,k,s, ..
        //min char variable rkh lo
        int n = s1.length();
        int m = baseStr.length();
        unordered_map<char, vector<char>> adj;
    
        for(int i=0;i<n;i++){
            adj[s1[i]].push_back(s2[i]);
            adj[s2[i]].push_back(s1[i]);
        }

        string ans;
        for(int i=0;i<m;i++){
            char ch = baseStr[i];
            vector<int> vis(26,0);  //isme min_char store hoga har char k corresponding
            char min_char = dfs(adj,ch, vis);
            ans+= min_char;
        }
        return ans;
    }
};