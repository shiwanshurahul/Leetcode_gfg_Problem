class Solution {
public:
void build_seg_tree(vector<int>& segTree, vector<int> & arr, int i, int s,int e){
    if(s == e){   //leaf pe ho
        segTree[i] = arr[s];   //or arr[e]
        return;
    }

    int mid = (s+e)/2;
    build_seg_tree(segTree, arr, 2*i+1, s, mid);  //build left subtree
    build_seg_tree(segTree, arr, 2*i+2, mid+1, e);  //build right subtree

    segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);   //dono child ka max
}

bool query_seg_tree(int i, int s, int e, vector<int> & segTree, int fruit){
        if(segTree[i] < fruit)   //no need to go down in tree bcz max hi store kr rhe node me
            return false;
        if(s == e){   // leaf pe hai jahan segTree[i] > fruits se bda rha hoga
            segTree[i] = -1000;   //assign fruits in this basket
            return true;
        }
        int mid = (s+e)/2;
        bool placed = 0;
        if(segTree[2*i+1] >= fruit)   //last subtree
            placed =  query_seg_tree(2*i+1, s, mid, segTree, fruit);
        else
            placed = query_seg_tree(2*i+2, mid+1, e, segTree, fruit);

        segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);  //bcz update kr rhe segTree    
        return placed;
}
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
       //can't sort bcz leftmost chahiye
        //baskets ko segment Tree me dalo , max store krlo parent me
        // 5
    //   5   4
    // 3   5  
        int n = baskets.size();
        vector<int> segTree(4*n, 0);
        build_seg_tree(segTree, baskets, 0, 0, n-1);  

        int unplaced = 0;
        for(auto it: fruits){
            if(query_seg_tree(0, 0, n-1, segTree, it) == false)
                unplaced++;
        }
        return unplaced;
        //left subtree me jane ka prayas    
    }
};