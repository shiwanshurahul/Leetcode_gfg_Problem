class Solution {
public:

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        //similar to asteroid collision   
        //collision tbhi hoga jb 1st right me and 2nd left me ja rhe hai

        //after wrong submission u realized ki reposiiton kro as based on which appears first on number line ->
        //i.e Sort robots by their positions to process them from left to right (0 to ..).
        int n = positions.size();
        vector<int> actual_indexes(n);
        for(int i=0;i<n;i++){
            actual_indexes[i] = i;  //0,1,2,3
        }
        auto lambda = [&](int a, int b) {
            return positions[a] < positions[b];
        };
        // sort(actual_indexes.begin(), actual_indexes.end(), cmp);
        sort(actual_indexes.begin(), actual_indexes.end(), lambda);
        //positions = [3,5,2,6] pe actual_index is: 2013
        //  ''        [5,4,3,2,1] ''                43210

        vector<int> ans;
        stack<int> st;

        for(auto i: actual_indexes){
            if(directions[i]=='R'){
                st.push(i); //index store kr rhe
            }
            else{  //'L' hai dirn
                while(!st.empty() && healths[i] > 0 ){  //= collision b/w right and this one
                    int right_idx = st.top();
                    st.pop();
                    if(healths[right_idx] > healths[i] ){ //curr elem
                        healths[right_idx] = healths[right_idx] - 1;  //quest me bol rhe
                        healths[i] = 0 ;
                        st.push(right_idx);
                    }
                    else if(healths[right_idx] < healths[i]){ //curr elem
                        healths[i] = healths[i] - 1;
                        healths[right_idx] = 0; 
                    }
                    else if(healths[right_idx] == healths[i]){
                            healths[right_idx] = 0;
                            healths[i] = 0;
                    }
                }
            }   
        }//end of for loop
        for(int i=0;i<n;i++){
            if(healths[i] > 0){
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};