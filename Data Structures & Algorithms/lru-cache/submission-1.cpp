class LRUCache {
public:
    int capacity = 0;
    list<pair<int, int>> q;
    unordered_map<int, list<pair<int, int>>::iterator> dict; 
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (dict.find(key) != dict.end()) {
            q.splice(q.begin(), q, dict[key]);
            return dict[key]->second;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (dict.find(key) != dict.end()) {
            q.splice(q.begin(), q, dict[key]);
            dict[key]->second = value;
        }
        else {
            if (capacity == q.size()) {
                dict.erase(q.back().first);
                q.pop_back();
            }
            pair<int, int> p = {key, value};
            q.push_front(p);
            dict[key] = q.begin();
        }
    }
};
