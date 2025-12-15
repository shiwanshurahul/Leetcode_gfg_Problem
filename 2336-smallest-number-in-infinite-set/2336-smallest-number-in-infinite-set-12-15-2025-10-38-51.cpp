class SmallestInfiniteSet {
public:
//minimize space complexity bcz here it is O(100001) with approach 1 .
//set lelo -> sorted set for num < i  and ek var for continuous
//
    set<int> st;
    int i = 1;  //continous 
    SmallestInfiniteSet() {
    }
    
    int popSmallest() {
        int smallest = 1e9;
        if(!st.empty()){  //smallest_no series se chota hai tbhi isme hau
            smallest = *st.begin();
            st.erase(st.begin());
            return smallest;
        }
        //else
        smallest = i;
        i++;
        return smallest;

    }
    
    void addBack(int num) {
        if(i>num && st.find(num) == st.end())    //i>num tbhi pichle no 
            st.insert(num);                           // ko set me dalo
    }
};// 1 2 3 

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */