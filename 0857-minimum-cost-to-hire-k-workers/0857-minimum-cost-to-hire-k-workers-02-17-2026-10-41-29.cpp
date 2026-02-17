class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        //qua = [10,20,5]
        //wag = [70,50,30], k=2
        //constrait = 1o^4 = o(nlogn)

        //agar kisi ka qua kisi ka half hai ya double hai toh curr 
        //worke ko us half/double wale ke wag ke resp me mile 
        //ratio equal ho i.e qua1/qua2 = wag1/wag2
        //e.g. 70/35 = 10/5 

      //Every worke in the paid group should be paid in the ratio
      //of their quality compared to other worker in the paid grp.

        //and very worke in the paid group must be paid at least 
        //their minimum wag expectation.
        //So for any two worker in the paid group,
        //we have wag[i]/wag[j] = quality[i]/quality[j]
        //So we have wag[i]/quality[i] = wag[j]/quality[j]
        //We pay wag to every worke in the group with the same
        //ratio compared to his own quality.

        //So to minimiz the total_wag, we want a small ratio.
        //So we sort all worker with their expected ratio, and pick
        // up K first worker.
        // Now we have a minim possible ratio for K worker and 
        //we their total quality.

        // As we pick up next worker with bigger ratio, we incras 
        //the ratio for whole group.
        // Meanwhile we remove a worker with highest quality so that
        // we keep K workers in the group.
        // We calculate the curr_ratio * total_qualit = total_wag 
        // for this group.

        //heap
        vector<vector<double>> w_q_ratio;
        for(int i=0;i<quality.size();i++){
            w_q_ratio.push_back({(double) wage[i]/quality[i], (double)quality[i]});
        }
        sort(w_q_ratio.begin(),w_q_ratio.end());
        //[[2.5,20], [6,5], [7,10]]
        priority_queue<int> pq;  //max heap
        double q_sum = 0;
        double ans = DBL_MAX;

        for(auto it: w_q_ratio){
            q_sum += it[1];
            pq.push(it[1]);
            if(pq.size() > k){
                q_sum -= pq.top(); 
                pq.pop();
            }
            if(pq.size() == k)
                ans = min(ans, q_sum * it[0]);    
        }
        return ans;
    }
};