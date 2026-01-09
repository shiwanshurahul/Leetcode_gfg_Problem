class Solution {
public:
//speed same hai sbka, agar same direction me ja rhe toh never collide
        // smaller wala explode hoga
        //e.g. [10,4,3,-6] -> 10; -6  3 and 4 ko destroy krdega
        // [-1,2]->never collide, [2,2] -> never collide
        // [2,-1]-> 2 
    vector<int> asteroidCollision(vector<int>& asteroids) {
        //colision will only happen when (+ pehle, then -) ho warna ni
        //sum lelo 2ono asteriod ka agar >0 then right jayega warna left
            stack<int> st;
            for(auto it: asteroids){
                int flag= 0;
                while(!st.empty() && st.top()>0 && it<0){ //only case of coll
                   int sum = st.top() + it;   //10-5 = 5
                    if(sum >0){
                        flag = 1;     //no need to push
                        break;
                    }
                    else if(sum <0){   //need to insert this -ve elem-5
                        st.pop();  //small = break
                    }
                    else{   //sum=0  8-8
                        st.pop();   //both destroyed
                        flag = 1;  //no need to push
                        break;
                    }
                } //while loop ke bad ye statement execute hoga
                if(flag !=1)   //baki ke 3 cases ya sum<0 wala case
                    st.push(it);
            } //end of for loop  
            
            int i = st.size()-1;
            vector<int> ans(st.size());
            while(!st.empty()){
                ans[i] = st.top();
                st.pop(); i--;
            }
            return ans;

    }
};