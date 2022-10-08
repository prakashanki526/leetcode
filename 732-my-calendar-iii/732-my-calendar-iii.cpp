class MyCalendarThree {
public:
    MyCalendarThree() {
        
    }
    
    map<int,int> mp;
    int book(int start, int end) {
        int sum=0,maxi=0;
        mp[start]++;
        mp[end]--;
        for(auto it:mp){
            sum += it.second;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */