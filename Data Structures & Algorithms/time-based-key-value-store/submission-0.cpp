class TimeMap {
public:
    TimeMap() {
        
    }
    map<string,map<int,string>> m;
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(m.find(key) == m.end()) return "";
        auto m1 = m[key];
        auto itr = m1.upper_bound(timestamp);
        if(itr == m1.begin()) return "";
        return (--itr)->second;
    }
};
