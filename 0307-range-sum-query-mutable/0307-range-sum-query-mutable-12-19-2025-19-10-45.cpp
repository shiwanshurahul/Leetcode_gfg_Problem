class NumArray {
public:
int n=0;
vector<int> segTree;
void buildTree(int s, int e, int i, vector<int>& nums,vector<int>& segTree){
    if(s == e){        //leaf pe ho
        segTree[i] = nums[s];   
        return;
    }
    int mid = (s+e)/2;
    buildTree(s, mid, 2*i+1, nums, segTree);    //left subtree
    buildTree(mid+1, e, 2*i+2, nums, segTree);  //right subtree

    //store ans -> upar ke nodes bharo
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

void update_segTree(int idx, int val, int i, int s, int e){
   
    if(s==e){   //us leaf pe ho to be updated
        segTree[i] = val;
        return ;
    }
    int mid = (s+e)/2;
    if(idx <=mid)   //goto left subtree
        update_segTree(idx, val, 2*i+1, s, mid);
    else   //goto right subtree
        update_segTree(idx, val, 2*i+2, mid+1, e);    

    //store ans -> upar ke nodes ko update
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int get_query_sum(int start, int end, int i, int s, int e){
    //3 cases
    if(s> end || e< start)  //out of bound
        return 0;
    if(s>= start && e<=end)  //completely inside range
        return segTree[i];
    //overlapping:
    int mid = (s+e)/2;
    return (get_query_sum(start, end, 2*i+1, s, mid) 
             +
        get_query_sum(start, end, 2*i+2, mid+1, e));

}

    NumArray(vector<int>& nums) {

        n = nums.size();
        segTree.resize(4*n,0);
        buildTree(0,n-1,0,nums,segTree); 
        // sbme s=0,i=0,e=n-1 bhejte
    }
    
    void update(int index, int val) {
       
        update_segTree(index,val,0,0,n-1); //update 1 idx
    }
    
    int sumRange(int left, int right) {
       
        return get_query_sum(left, right, 0, 0, n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */