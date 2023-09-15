class Solution {
public:
    int largestRectangleArea(vector<int>& heights){

        int max_area = 0, last_ind_popped = 0, area;
        std::pair<int, int> ind_val(0, heights[0]);
        std::stack<std::pair<int, int>> st;
        st.push(ind_val);

        for(int i = 1; i < heights.size(); i++){
            if(heights[i] < st.top().second){
                while(!st.empty() && st.top().second > heights[i]){
                    area = st.top().second * (i - st.top().first);
                    if(area > max_area) max_area = area;
                    last_ind_popped = st.top().first;
                    st.pop();
                }
                ind_val.first = last_ind_popped;
                ind_val.second = heights[i];
                st.push(ind_val);
            }
            else{
                ind_val.first = i;
                ind_val.second = heights[i];
                st.push(ind_val);
            }
        }
        while(!st.empty()){
            area = ((heights.size() - st.top().first) * st.top().second);
            if( area > max_area) max_area = area;
            st.pop();
        }
        return max_area;
    }
};