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
        unordered_set<string> st = {supplies.begin(),supplies.end()};
        vector<bool> cooked(n,0);

        vector<string> ans;
        int cnt = n;

        while(cnt--){
            for(int i=0;i<n;i++){
                if(cooked[i] == true)
                    continue; //already bn chuka
                //else:
                bool banega_recipe = 1; //for each recipe
                for(int j=0;j<ingredients[i].size();j++){  //ingredient
                    if(st.find(ingredients[i][j]) == st.end() ){
                        banega_recipe = 0; 
                        break;    //dusre recipe try kro filhal
                    }    
                }   
                if(banega_recipe){
                    ans.push_back(recipes[i]);
                    cooked[i] = true;
                    st.insert(recipes[i]);  //supply me daldo
                }
            }
        }
        return ans;


        //directed graph
        //toposort -> cycle wale nodes ka indegree 0 ni hoga 
        //= q me never push



    }
};