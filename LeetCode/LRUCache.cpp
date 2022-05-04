class LRUCache {
public:
    int capacity;
    map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> cacheOrder;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(cache.count(key)){
            updateOrder(key, cache[key]->second);
            return cacheOrder.front().second;
        }
        // cout << "Cache:";
        // for(auto c : cache){
        //     cout << " {" << c.first << ", {" << c.second->first << ", " << c.second->second << "}},";
        // }
        // cout << endl;
        // cout << "CacheOrder:";
        // for(auto c : cacheOrder){
        //     cout << " {" << c.first << ", " << c.second << "},";
        // }
        // cout << endl;
        
        return -1;
    }
    
    void put(int key, int value) {        
        if(cache.count(key)){
            // cout << "Updating key " << key << " value from " << cache[key] << " to " << value << endl;
            updateOrder(key, value);
        }else{
            // cout << "Adding key " << key << " with value " << value << endl;
            cacheOrder.push_front({key, value});
            cache[key] = cacheOrder.begin();
        }

        if(cacheOrder.size() > capacity){
            // cout << "Over capacity\n";
            remove();
        }
    }
    
    void updateOrder(int key, int value){
        cacheOrder.erase(cache[key]);
        cacheOrder.push_front({key, value});
        cache[key] = cacheOrder.begin();
    }
    
    void remove(){
        // cout << "Removing: {" << cacheOrder.back() << ", " << cache[cacheOrder.back()] << "}\n";
        cache.erase(cache.find(cacheOrder.back().first));
        cacheOrder.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */