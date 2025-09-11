class Solution {
public:  //tree me cycle ni hota toh vis array ki need ni hai
//N-ary tree: root is headId -> iske employee -> iske employee
    int max_time = 0;
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        //manager array me har employee ka manager de rkha hai
        //information is going manager to employee and iska time nikalna hai -> adjlist banao aise
        //curr employee ko subordinate tak information bhejne me informTime[i] lgta
        unordered_map<int, vector<int>> adj;   //manager ->child1,child2,child3
        for(int i=0;i<n;i++){
                if(manager[i] !=-1)
                    adj[manager[i]].push_back(i);  // ''
            }

            dfs(adj,informTime, headID, 0);  //employee, curr time

            return max_time;
    }
    void dfs(unordered_map<int,vector<int>>& adj, vector<int> &informTime, int employee, int time){
        max_time = max(max_time, time);
        for(auto it: adj[employee]){
            dfs(adj,informTime,it, time+informTime[employee]);
        }
    }
};