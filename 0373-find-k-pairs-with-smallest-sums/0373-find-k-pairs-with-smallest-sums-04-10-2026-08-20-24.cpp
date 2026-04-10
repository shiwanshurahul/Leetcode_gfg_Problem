class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        //for loop chalak chk krlo sbse min 3 pair
        priority_queue<pair<int,pair<int,int> >>pq;//max heap
             //{sum,{nums[i],nums[j]}};

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum = nums1[i] + nums2[j]; //[1,2] [1,4], [1,6]
                if(pq.size()<k){
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else if(sum<pq.top().first){ //sum<sum
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                else{
                    break; //from j loop->ab idhr j me ans ni hai = i++
                }
            }
        }
        //k^2logn

        vector<vector<int>> ans;
        while(!pq.empty()){  // k elements hi hai
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};