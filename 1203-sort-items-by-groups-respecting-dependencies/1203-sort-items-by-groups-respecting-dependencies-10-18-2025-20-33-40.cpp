class Solution {
public:
vector<int> toposort(unordered_map<int, vector<int>>&adj, vector<int>& indegree){
    //kahn's algo for toposort -> cycle me indegree 0 ni hogi = never pushed to q 
    queue<int> q;
    for(int i=0;i<adj.size();i++){
        if(indegree[i]==0)
            q.push(i);
    }
    
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }
    }

    return ans.size() == adj.size() ? ans :  vector<int> () ; //warna cycle aa rha
}
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // n items, m groups
        // ith item belongs group[i] or -1 = no grp
        
        //same grp wale next to each other aaye
        //beforeItems wale pehle aaye
        //i.e if beforeItems[3] = {5,6} then {5,6,3} aise aye = directed edge

        //items and group dono ka ordering kro = dono ka toposort

        for(int i=0;i<n;i++){
            if(group[i]==-1)  //no grp
                group[i] = m++; //sbko naye grp me dalo
        }

        unordered_map<int, vector<int>> adj_items, adj_group;
        for(int i=0;i<n;i++){
            adj_items[i] = vector<int>();
        }
        for(int i=0;i<m;i++){
            adj_group[i] = vector<int>();
        }
        vector<int> indegree_items(n,0);
        vector<int> indegree_group(m,0);

        for(int i=0;i<n;i++){
            for(auto prev: beforeItems[i]){  //pehle jo aane chahiye
                adj_items[prev].push_back(i);  //prev ke bad i = prev->i
                indegree_items[i]++;

                if(group[i] != group[prev]){  //alag grp
                    int prev_item_ka_group = group[prev];
                    int curr_item_ka_group = group[i];

                    adj_group[prev_item_ka_group].push_back(curr_item_ka_group);  // prev_item_ka_group->curr_item_ka_group
                    indegree_group[curr_item_ka_group]++;
                }
            }
        }

        //get toposort of both items and group
        vector<int> items_order = toposort(adj_items, indegree_items);
        vector<int> group_order = toposort(adj_group, indegree_group);

        if(items_order.empty() || group_order.empty())
            return {};

        unordered_map<int, vector<int>> ordered_grp;

        for(auto item: items_order){
            int item_grp = group[item];
            ordered_grp[item_grp].push_back(item); 
        }

        vector<int> ans;
        for(auto it: group_order){  //toposrt se grp ka jo aa rha uspe iterate
            ans.insert(ans.end(), ordered_grp[it].begin(), ordered_grp[it].end() );
        }
        return ans;

    }
};