class Solution {
public:
void dfs(unordered_map<string, vector<pair<string,double>>>& adj,unordered_set<string> &vis, string src, string dest, double &prod, double temp){
    
    vis.insert(src);  //mark visited
    if(src == dest){
        prod = temp;
        return ;  
    }    

    for(auto it:adj[src]){  //adj list me string, double
        string v = it.first;
        double val = it.second;
        if(vis.find(v) == vis.end())
            dfs(adj,vis,v,dest,prod,temp*val);
    }      

}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //  2     1/2       3      1/3
        //a-->b ; b-->a ; b-->c ; c-->b

        //store like a undirectd grap
    
        vector<double> ans;
        unordered_map<string, vector<pair<string,double>>> adj;
        for(auto i=0;i<equations.size();i++){
            string u = equations[i][0];  //"a"
            string v = equations[i][1];  //"b"
            double val = values[i];      //2.0

            adj[u].push_back({v,val}); //"a" --> "b"
            adj[v].push_back({u,1.0/val}); //"b" --> "a"
        }

        for(auto it: queries){
            string src = it[0];
            string dest = it[1];
            double prod = -1.0;
            double temp = 1.0;

            if(adj.find(src) == adj.end() || adj.find(dest) ==adj.end()){
                prod = -1.0;   //adj me src ya dest ni hai
            }
            else{  
                unordered_set<string> vis; //for each query
                dfs(adj,vis,src,dest,prod,temp);
            }
            ans.push_back(prod);
        }
        return ans;

    }
};