class DisjointSet  {
    vector<int> parent;
public:   
    DisjointSet(int n){  //constructor
        parent.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
    }
    int find_parent(int node) {
        // add code here
        if(node==parent[node])   //apna parent
            return node;   //is set ka ye hi parent/representative hai
        
        return find_parent(parent[node]);   //parent[node] ka parent dhundhte jao 
    }

    void unionSet(int u, int v) { //utlimate parent to which u belongs,
                                 //  utlim. parent to which v belongs me merge  
        // add code here.
        int u_parent = find_parent(u);
        int v_parent = find_parent(v);
        
        if(u_parent != v_parent)   //warna already same set me hai
            parent[u_parent] = v_parent;  //u ko parent bna rhe v ka 
    }
};
class Solution {   
public://dsu -> parent ke sath merge krte
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        //merge kro if common email hai do list me toh, name se fark ni pdta
        // = disjoint set -> dsu, dsf -> initially sb independent hai and apne parent hai
        //idx store krado and usipe union krdo
        // j1@com, j2@com, j3@.com -> 0  (email store krdo)
        // j4@.com -> 1
        // r1@.com, r2@.com -> 2
        // j3@.com, j4@.com -> 3 = merge 3 with 0 ka utimate parent = 3 ka parent is 0 ab
        // j4@.com, j5@.com -> 4 = merge 4 with 3 ka ultimate parent = 4 ka parent v 0
        // ultimate parent me insert krdo 
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> mp;  //{mail,idx}

        for(int i=0;i<n;i++){  //iterate on i ke emails
            for(int j=1;j<accounts[i].size();j++){  //bcz j=0 is name
                string mail = accounts[i][j];
                if(mp.find(mail) == mp.end()) //not exists
                    mp[mail] = i;
                else        //j3@.com already exists
                    ds.unionSet(i,mp[mail]); //curr idx and stored idx
            }
        }
        vector<string> merged_mail[n];
        for(auto it: mp){
            string mail = it.first; 
            int node = ds.find_parent(it.second); 
            merged_mail[node].push_back(mail);
        } //[0] -> xyz,abc ; [1] -> dfg
       
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(merged_mail[i].size()==0)
                continue;
            sort(merged_mail[i].begin(), merged_mail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); //name
            for(auto it: merged_mail[i]){
                temp.push_back(it);
            }    
            ans.push_back(temp);
        }
        return ans;
    }
};