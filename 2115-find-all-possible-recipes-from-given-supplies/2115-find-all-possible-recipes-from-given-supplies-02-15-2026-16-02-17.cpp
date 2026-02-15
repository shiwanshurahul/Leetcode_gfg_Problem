class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        //A recipe can be ingredient for any other recipe
        // = jaise hi koi recipe bn jaye add it to supplies

        //ho skta kuch avi ni bn rha bt bad me bn
        //recipe = ["sandwich" "bread"]
        //ingre = [("bread","veggies"), ("yeast","flour")]
        //supplies=["yeast","flour","veggies"] 

        //here, sandwich intially ni bn skta as bread is not there
        //but bread ke bnne ke bad bna skte
        //= avi age jao and isko mark krlo and last me try kr lena is pe

        //brute force -> search        
        //sb vector me hai = search me time lgega = st me daldo = 0(1)

        int n = recipes.size();
        // unordered_set<string> st = {supplies.begin(),supplies.end()};
        // vector<bool> cooked(n,0);

        vector<string> ans;
        // int cnt = n;  //itni bar chalao loop 

        // while(cnt--){
        //     for(int i=0;i<n;i++){
        //         if(cooked[i] == true)
        //             continue; //already bn chuka
        //         //else:
        //         bool banega_recipe = 1; //for each recipe
        //         for(int j=0;j<ingredients[i].size();j++){  //ingredient
        //             if(st.find(ingredients[i][j]) == st.end() ){
        //                 banega_recipe = 0; 
        //                 break;    //dusre recipe try kro filhal
        //             }    
        //         }   
        //         if(banega_recipe){
        //             ans.push_back(recipes[i]);
        //             cooked[i] = true;
        //             st.insert(recipes[i]);  //supply me daldo
        //         }
        //     }
        // }  //T.C  = o(n*n*m)
        // return ans;

        //m2:
        //bread bnega tbhi sandwich bn skta -> directed graph
        // toh pehle bread aaega fir sandwich aega = order hai
        // = toposort

        //toposort -> kahn's algo = cycle wale nodes ka indegree 0 
        // ni hoga = q me never push

        //adj list: -> normal toh unordered_map<int, vector<int>> adj;
        //here, ingredient -> recipe_idx1, recipe_idx2, ..
        unordered_set<string> st = {supplies.begin(),supplies.end()};
        unordered_map<string, vector<int>> adj;

        vector<int> indegree(n,0);

        for(auto i=0;i<n;i++){  //recipe
            for(auto it: ingredients[i]){ //string
                if(st.find(it) == st.end()){ //not present = dependncy
                    adj[it].push_back(i); //dependent hai ispe
                    indegree[i]++;  // since, it->i hai
                }
            }
        }
        //indegree = 0 ko q pe push
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);  //not dependent on anythin
        }

        while(!q.empty()){
            int node = q.front();  //idx of recipe
            q.pop();
            string recip = recipes[node];
            ans.push_back(recip);

            for(auto it: adj[recip]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }
        return ans;
    }
};