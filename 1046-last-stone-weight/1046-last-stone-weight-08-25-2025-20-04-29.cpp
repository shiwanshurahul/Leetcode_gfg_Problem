class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;    // max heap
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }    
            while(pq.size()>1){
                int x = pq.top(); pq.pop();
                int y = pq.top(); pq.pop();
                pq.push(abs(x-y));    
           
        }
        //1 stone in pq 
       return pq.top();
    }
};