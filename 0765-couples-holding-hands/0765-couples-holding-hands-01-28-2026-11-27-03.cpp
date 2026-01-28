class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        //aise lao (0,1,2,3) ya (3,2,0,1) order doesn't matter
        //min swap req to sort the arr ni hai as
        // Input: row = [3,2,0,1]
        // Output: 0

        //2 no at a time dekho idx 0 se
        //first no is even toh we expect no+1 on its right
        //e.g. 0->1 , 2->3
        // and vice-versa with odd -> no - 1
        //1->0, 3->2 as pairing defined hai
        int n = row.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[row[i]] = i;  //{val,idx}
        } //{0,0} {2,1} {1,2} {3,3}
        
        int ans = 0; //no of swaps
        for(int i=0;i<n;i+=2){
            int first = row[i]; //curr no
            int second = first + (row[i]%2 ==0 ? 1 : -1); //expected 
            if(row[i+1] !=second){ //next no is not expected no
                ans++;
                swap(row[i+1], row[mp[second]]); //legal val
                //update mp:
                mp[row[i+1]] = second;
                mp[second] = i+1;
            }
        }
        return ans;
    }  //i=0: first=0, second = 1, row[i+1] = 2
       // = row[0,1,2,3], mp[2] = 1, mp[1] = 1
};