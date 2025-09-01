class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
         //maximize the average pass ratio across all the classes.
         // jisme v pass_ratio max increse ho rha (delta) usme ek ek krke students dalo

       int n = classes.size();
       priority_queue<pair<double,int>> pq;  //max heap
  
       for(int i=0;i<n;i++){
        double curr_pr = (double) classes[i][0]/classes[i][1];
        double increa_pr = (double) (classes[i][0]+1) / (classes[i][1]+1);
        double delta = increa_pr - curr_pr;
        pq.push({delta, i});
       }

       while(extraStudents--){
        auto curr = pq.top(); 
        pq.pop();

        double delta = curr.first;
        int idx = curr.second;

        classes[idx][0]++;  //increasing students in that class
        classes[idx][1]++;

        //firse push kro heap me
        double curr_pr = (double) classes[idx][0]/classes[idx][1];
        double increa_pr = (double) (classes[idx][0]+1)/(classes[idx][1]+1);
        double updated_delta = increa_pr - curr_pr;
        pq.push({updated_delta, idx});

       }
        
        double max_avg = 0.0;
        for(auto it: classes){
                max_avg += (double)it[0]/it[1];   
        } 

       return max_avg/n;
    }//0.42
};