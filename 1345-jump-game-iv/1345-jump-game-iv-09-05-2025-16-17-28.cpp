class Solution {
public:
    int minJumps(vector<int>& arr) {
        //i-1,i+1, arr[i] = arr[j] pe jump
        //map me store same val ke idx
        // e.g. 100-> 0,4
        //bfs -> q me idx dalo; dfs se tle bcz recursive call hota
        int n = arr.size();
        unordered_map<int,vector<int>> mp;
        vector<int> visited(n,0);

        queue<int> q;

        for(int i=0;i<n; i++){
            mp[arr[i]].push_back(i);   //aisa hi adj list hota
        }
        q.push(0); visited[0] = 1;

        int steps = 0;

        while(!q.empty()){
            int siz = q.size();
            while(siz--){
                int curr = q.front();
                q.pop();

                int left = curr-1;
                int right = curr+1;

                if(curr==n-1)
                    return steps;

                if(left>=0 && !visited[left]){    //not visited
                    q.push(left);
                    visited[left] = 1;
                }
                if(right <=n-1 && !visited[right]){    //not visited
                    q.push(right);
                    visited[right] = 1;
                }
                for(auto it: mp[arr[curr]]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = 1;
                    }
                }

                mp.erase(arr[curr]); //already q me dal chuke toh kisi neighbour ke through wapas v aa skta toh duplicate hoga
            }
            steps++;
        }

        return steps;
        
    }
};