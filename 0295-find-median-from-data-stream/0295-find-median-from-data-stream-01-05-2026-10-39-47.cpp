class MedianFinder {
public:
//bar bar sort krke can't return middle
// = 2 heap rkho = stores in sorted way
//pehla maxh_left and 2nd is minh_right
//123 ; 456 -> median = even = maxh_left.top() + minh_right.top() /2; 
//123 ; 45 -> median = odd =  maxh_left.top(); 

//maxh_left size ya toh equal ya toh 1 greater than minh_right

    priority_queue<int> maxh_left;
    priority_queue<int, vector<int>, greater<int>> minh_right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxh_left.empty() || maxh_left.top() > num)
            maxh_left.push(num);   //num chota hai maxh_left ke top se
        else
            minh_right.push(num);    

        //pushed, maintain the size of both heaps

        if(abs( (int)maxh_left.size() ) - abs( (int)minh_right.size()) > 1){
            minh_right.push(maxh_left.top());
            maxh_left.pop();
        }
        else if(minh_right.size() > maxh_left.size()){ //ni rkh skte
            maxh_left.push(minh_right.top());
            minh_right.pop();
        }
    }
    
    double findMedian() {
        if(maxh_left.size() == minh_right.size())  //even size
            return (double) ( maxh_left.top() + minh_right.top() )/2; 
        else
            return (double) maxh_left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */