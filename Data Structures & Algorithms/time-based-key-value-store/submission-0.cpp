class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>>values;

    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        values[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
                
        if(values.find(key) == values.end()) return "";

        auto & history = values[key];

        auto it = upper_bound(history.begin(), history.end(), make_pair(string(""), timestamp), [](const pair<string, int>& a, const pair<string, int>& b) {
                return a.second < b.second;
            });

        if(it == history.begin()) return "";

        return (prev(it)) -> first;
    }
};
