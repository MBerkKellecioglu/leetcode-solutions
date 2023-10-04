class TimeMap{
public:
    std::unordered_map<string, std::vector<std::pair<string, int>> > main_mp;
    TimeMap(){
    }
    
    void set(string key, string value, int timestamp){
        main_mp[key].push_back({value,timestamp});    
    }
    
    string get(string key, int timestamp){
        int left_ind = 0, right_ind = main_mp[key].size() - 1, mid_ind;
        string sol = "";
        
        while(left_ind <= right_ind){
            mid_ind = (left_ind + right_ind) / 2;
            if(main_mp[key][mid_ind].second < timestamp){
                left_ind = mid_ind + 1;
                sol = main_mp[key][mid_ind].first;
            }
            else if(main_mp[key][mid_ind].second > timestamp) right_ind = mid_ind - 1;
            else return main_mp[key][mid_ind].first;
        }

        return sol;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */