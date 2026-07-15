class TimeMap {
public:
    map<string, vector<pair<int, string>>> storage;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        storage[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& target = storage[key];
        if (storage.find(key) == storage.end()) return "";

string res = "";
int l = 0, r = target.size() - 1;
while (l <= r) {
    int mid = l + (r - l) / 2;
    if (target[mid].first <= timestamp) {
        res = target[mid].second; // Found a candidate
        l = mid + 1; // Try to find a larger timestamp
    } else {
        r = mid - 1;
    }
}
return res;
    }
};
