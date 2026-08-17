class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        int left, right, middle;
        left = 0;
        right = hash[key].size() - 1;
        middle = left + (right - left) / 2;
        string recent = "";

        while (left <= right) {
            if (hash[key][middle].second == timestamp) {
                return hash[key][middle].first;
            }
            else if (hash[key][middle].second > timestamp) {
                right = middle - 1;
            }
            else {
                recent = hash[key][middle].first;
                left = middle + 1;
            }
            middle = left + (right - left) / 2;
        }
        return recent;
    }

private:
    unordered_map<string, vector<pair<string, int>>> hash;
};
