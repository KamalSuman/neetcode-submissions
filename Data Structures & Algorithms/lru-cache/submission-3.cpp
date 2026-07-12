class LRUCache {
public:
    int cp = 0, sz = 0;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    list<pair<int,int>> dll;
    LRUCache(int capacity) {
        cp = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        auto it = m[key];
        dll.splice(dll.begin(),dll,it);
        return it->second;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            m[key]->second = value;
            dll.splice(dll.begin(),dll,m[key]);
            return;
        }
        
        if(dll.size() == cp){
            m.erase(dll.back().first);
            dll.pop_back();
        } 

        dll.push_front({key,value});
        m[key] = dll.begin();
    }
};
