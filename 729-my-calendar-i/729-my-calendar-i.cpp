class MyCalendar {
public:
    map<int,int>dates;
    MyCalendar() {
       
    }
    
    bool book(int start, int end) {
        auto last = dates.upper_bound(start);
        if(last != dates.end() && last->second <end){
            return false;
        }
        dates.insert({end,start});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */