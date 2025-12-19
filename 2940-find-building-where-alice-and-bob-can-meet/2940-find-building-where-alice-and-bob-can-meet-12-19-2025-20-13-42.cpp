class Solution {
public:
void buildTree(int s, int e,int i, vector<int> &segTree, vector<int> &arr){
    if(s==e){
        segTree[i] = s; //idx store kr rhe or e
        return;
    }
    int mid =(s+e)/2;
    buildTree(s, mid, 2*i+1, segTree, arr);   //left subtree 
    buildTree(mid+1, e, 2*i+2, segTree, arr); //right subtree

    //store idx -> upar ke nodes bharo using leaf
    if(arr[segTree[2*i+1]] >= arr[segTree[2*i+2]])
        segTree[i] = segTree[2*i+1]; //max val wale child ka idx store 
    else
        segTree[i] = segTree[2*i+2]; 
}
//returns the idx of max elem in the range (start, end)
int range_max_index_query(vector<int> &segTree, vector<int>& arr, int start, int end, int i, int s, int e){
    //3 cases -> similar as range sum query 
    if(start > e || s > end)  //completely out of range 
         return -1;
    
    if(s >= start && e <= end)  //s,e is completely inside range start, end
        return segTree[i];
    //else overlapping:
    int mid = (s+e)/2;  
    int leftIdx = range_max_index_query(segTree, arr, start, end, 2*i+1, s, mid);
    int rightIdx = range_max_index_query(segTree, arr, start, end, 2*i+2, mid+1, e);
    if(leftIdx ==-1)
        return rightIdx;
    else if(rightIdx ==-1)
        return leftIdx;
    return (arr[leftIdx] >= arr[rightIdx]) ? leftIdx : rightIdx;
}

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        //queries are a and b jahan wo hai
        //aisa building khojo leftmost jiska height dono se bada ho 
        //for q:[a,b] -> b pe ja skte agar height[a] < height[b] 

        //segTree, RMIQ -> range me max elem ka idx, BS
        int n = heights.size();
        vector<int> segTree(4*n ,0); //segTree me idx store (max val wale child ka)for RMIQ
        buildTree(0,n-1,0,segTree,heights);  //s,e,i

        vector<int> ans;
        //ab RMIQ laga do after queries[1] to n-1:
        for(auto it: queries){  //[0,1] -> [1,0] v aa skta
            int min_idx = min(it[0], it[1]);
            int max_idx = max(it[0], it[1]);
            int res = -1;

            if(min_idx == max_idx){
                ans.push_back(min_idx);  //same building pe hai already 
                continue;
            }
            else if(heights[min_idx] < heights[max_idx]){
                ans.push_back(max_idx); //height[a] < height[b] toh b pe mile
                continue;
            }
            int s = max_idx + 1;
            int e = n-1;

            //b.s
            while(s<=e){
                int mid = (s+e)/2;
                int RMIQ_idx = range_max_index_query(segTree,heights,s,mid,0,0, n-1);  //  start, end, i, s, e
                if(heights[RMIQ_idx] > max(heights[min_idx], heights[max_idx])){
                    res = RMIQ_idx;  //right me hai of a & b = valid
                    e = mid-1;  //aur left me chk krlo
                }
                else{
                    s = mid+1;
                }
            } //end of while
            ans.push_back(res);
        } //end of for loop
        return ans;
        
    }
};