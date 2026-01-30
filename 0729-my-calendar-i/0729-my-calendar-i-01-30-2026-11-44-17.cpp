class MyCalendar {
public:
vector<pair<int,int>>v;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        //[10,20],[20,30]
        //check for overlapping -> endTime(prev t) >startTime
        //startTime me aa rha
        for(auto it: v){
            // if( it.second > startTime && endTime >it.first )
            //     return false;   //warna thik hai
            //m2:
            if(max(startTime,it.first) < min(endTime,it.second))
                return false;
        }
        v.push_back({startTime,endTime}); 
        return true;
    }
};//general: check overlap for(a1,b1) (a2,b2) : max(a1,a2) < min(b1,b2) = overlap hai a2 se b1 tak

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */