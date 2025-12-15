class SmallestInfiniteSet {
public:
    vector<int> v;
    int i=1;
    SmallestInfiniteSet() {
        v.resize(100001,1);
        i=1;
    }
    
    int popSmallest() {
        int smallest = i;
        v[i] = 0;
        //update i for next smallest:
        int j = i+1;
        while(v[j] == 0 && j<v.size()){
            j++;
        }
        i = j;  //first non zero wala index
        return smallest;
    }
    
    void addBack(int num) {
        v[num] = 1;
        if(i > num)
            i = num;
    }
};// 1 2 3 

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */