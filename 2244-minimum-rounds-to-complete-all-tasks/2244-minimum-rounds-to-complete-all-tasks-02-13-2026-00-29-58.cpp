class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
         priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
       

       int cnt =0;
       unordered_map<int,int> mp;

       for(auto it:tasks){
           mp[it]++;
       }
       
       for(auto it:mp){
           if(it.second<2){
               return -1;
           }
            else if(it.second>3){
               if(it.second>3 && it.second%3!=0)
               cnt =cnt+1+ (it.second/3);
               else
               cnt =cnt+ (it.second/3);
           }
           else{
               cnt++;
           }
       }
       return cnt;
       /*  for(auto it=mp.begin();it!=mp.end();it++){
             pq.push({it->first,it->second});
         }

       //  int flag=0;
         while(!pq.empty()){
             int flag=0;
             long int k =pq.top().first;
             long int l =pq.top().second;
             if(l<2)
             return -1;
             int o=0,u =l;
            if(u>3 && u%3==0){
                flag =1;
            o =u/3;
             }
             else if(u>3 && u%3!=0){
                 flag= 1;
                 o =(u/3) +1;
             }
             if(flag==1){
             cnt= cnt+ o;
              pq.pop();
             }
             else if(flag==0){
            pq.pop(); cnt++;}
         }
         return cnt;*/
    }
};