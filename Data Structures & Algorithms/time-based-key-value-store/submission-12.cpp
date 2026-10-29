class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (mp.find(key) == mp.end()) return "";
        auto& vec = mp[key];
        int left = 0;
        int right = vec.size();
        while (left < right) { // find first index > timestamp
            int mid = left + (right - left) / 2;
            if (vec[mid].second > timestamp) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return (left == 0) ? "" : vec[left - 1].first;
    }
};
