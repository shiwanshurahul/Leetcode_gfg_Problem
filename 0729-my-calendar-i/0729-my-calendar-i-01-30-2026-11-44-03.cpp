class MyCalendar {
public:
vector<pair<int,int>>v;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        //[47,50],[33,41],[39,45]
        for(auto it: v){
           if(startTime <it.second && endTime > it.first )
           return false;   //warna thik hai
       }
        v.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */