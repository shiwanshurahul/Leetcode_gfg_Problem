class Solution {
public:
vector<string> ans;
int num_tickets = 0;
void solve(string src, unordered_map<string,priority_queue<string, vector<string>, greater<string>>>& adj, vector<string>& v ){

    auto &it = adj[src];
    while(!it.empty()){
        string to = it.top();
        it.pop();
        solve(to,adj,v);
    }
    v.push_back(src);  //normal dfs me sbse pehle push krte

}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //u must use all ticket/edges
        //so, if v.size() = tickets+1 then return
        //  JFK  ->>A
        //  | |
        //  | | //arrow manlo B pe and JFK pe
        //   B              
          //by lexicgraphically A pe jaenge par sare tckets use ni huye = backtrack so, path is JFK ->B->JFK -> A
          //e.g. jb multipl ho tb lexicographicaly

        unordered_map<string, priority_queue<string,vector<string>,greater<string>>> adj;
        num_tickets = tickets.size();
        for(auto it: tickets){
            string u = it[0];
            string v = it[1];

            adj[u].push(v); //directed
        }
        //sort vertices in adj list for lexicographicall
        // for(auto it: adj){ //agar vector<strin> lete toh krte avi toh min heap liya hai
        //     sort(it.second.begin(), it.second.end());
        // }
        //euler pat ka quest ha
        vector<string>v; 
        solve("JFK",adj,v); //start "JFK" se hi hoga
        reverse(v.begin(), v.end());
        return v;
    }
// };This is variaton of dfs.
// The way to tweak the dfs is to not to put a base condition and let the dfs fill and tsack and empty itslef
// What i mean by this is 

// Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
// Lets say we built a graph of this and its adjacenecy list look like this:-
// JFK - MUC
// MUC - LHR
// LHR - SFO
// SFO - SJC

// So when we perform a dfs on JFK

// |        |
// |        |
// |        |   <-----Recursion Stack
// |        |
// |__JFK___|

// We explore JFKs neighbors 

// |        |
// |        |
// |        |
// |  MUC   |
// |__JFK___|

// We explore Muc neighbors

// |        |
// |        |
// |  LHR   |
// |  MUC   |
// |__JFK___|

// |        |
// |  SFO   |
// |  LHR   |
// |  MUC   |
// |__JFK___|

// |  SJC   |
// |  SFO   |
// |  LHR   |
// |  MUC   |
// |__JFK___|

// Since SJC has no neighbors we pus it back to the answer

// |        |
// |  SFO   |      ans=SJC
// |  LHR   |
// |  MUC   |
// |__JFK___|

// |        |
// |        |      ans=SJC,SFO
// |  LHR   |
// |  MUC   |
// |__JFK___|

// |        |
// |        |      ans=SJC,SFO,LHR
// |        |
// |  MUC   |
// |__JFK___|


// |        |
// |        |      ans=SJC,SFO,LHR,MUC 
// |        |
// |        |
// |__JFK___|

// |        |
// |        |      ans=SJC,SFO,LHR,MUC,JFK 
// |        |
// |        |
// |________|

// We reverse the array and return it.