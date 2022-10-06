class TimeMap {
public:
     unordered_map<string,map<int,string>> data;
    TimeMap() {
       
    }
    
    void set(string key, string value, int timestamp) {
        data[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        // if(mp.find(key)==mp.end())
        //     return NULL;
        // string res;
        // for(auto it:mp[key]){
        //     if(it.first>timestamp)
        //         return res;
        //     else{
        //         res = it.second;
        //     }
        // }
        // return res;
        
          if (!data.count(key)) return "";
        auto it = data[key].lower_bound(timestamp);
        if (it != data[key].end() && (*it).first==timestamp) 
            return (*it).second;
        if (it == data[key].begin()) return "";
        --it;
        return (*it).second;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */