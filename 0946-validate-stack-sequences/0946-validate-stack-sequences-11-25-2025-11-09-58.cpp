class Solution {
public:
// 5 4 3 2 1 -> 
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i=0;
        for(auto it : pushed){
         st.push(it);  //1 2 3 4 ;1 2 3 5 ;1 2 3; 1 2; 1
         //while loop to check the condition
     while(!st.empty() && st.top()==popped[i]){
         st.pop(); //4==4=i=1; 5==5==i=2; 3==3 =i=3; 2==2=i=4; 1==1=i=5
            i++;
         }
        }
        if(st.empty())
        return 1;
        return 0;
    }
};//1 2 3 4  -> 4 3 -> 1 2 5 -> 1 sbse neeche  = X 