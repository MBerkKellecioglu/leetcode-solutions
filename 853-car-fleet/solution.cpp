class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed){

        std::pair<int, int> pos_speed;
        std::vector<std::pair<int, int>> all_cars;
        std::stack<std::pair<int, int>> st;
        float time , time2;

        for(int i = 0; i < position.size(); i++){
            pos_speed.first = position[i];
            pos_speed.second = speed[i];
            all_cars.push_back(pos_speed);
        }
        sort(all_cars.begin(), all_cars.end());

        time = float((target - all_cars.back().first)) / float((all_cars.back().second));
        st.push(all_cars.back());

        for(int i = all_cars.size() - 2; i > - 1; i--){
            time2 = float((target - all_cars[i].first)) / float((all_cars[i].second));
            if(time2 <= time) continue;
            else{
                time = time2;
                st.push(all_cars[i]);
            }
        }
        return st.size();
    }
};