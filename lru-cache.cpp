class LRUCache{
public:
    int capacity;
    map<int, int> time2key; // time : key
    unordered_map<int, int> key2value;   // key : value
    unordered_map<int, int> key2time; // key : time
    int id = 0;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (key2value.count(key) > 0){
            time2key.erase(key2time[key]);
            key2time[key] = id;
            time2key[id] = key;
            id++;
            return key2value[key];
        }
        else{
            return -1;
        }
    }
    
    void set(int key, int value) {
        if (key2value.count(key) == 0 && capacity == key2value.size()){
            key2value.erase(time2key.begin()->second);
            key2time.erase(time2key.begin()->second);
            time2key.erase(time2key.begin());
        }
        if (key2value.count(key) > 0){
            time2key.erase(key2time[key]);
        }
        key2value[key] = value;
        time2key[id] = key;
        key2time[key] = id;
        id++;
    }
};
