class TimeMap {
public:
    unordered_map<string, vector<pair<string, int>>> umap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        umap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto elem = umap[key];

        if(elem.size() == 0) return "";

        int left = 0, right = elem.size() - 1;
        string res = "";
        int idx = -1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(timestamp == elem[mid].second) return elem[mid].first;
            else if(timestamp > elem[mid].second){
                res = elem[mid].first;
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return res;
    }
};
