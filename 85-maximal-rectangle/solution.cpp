class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix){

        int max_area = 0, n = matrix.size(), m = matrix[0].size();

        vector<int> heights(m, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            max_area = max(max_area, largestRectangleArea(heights));
        }

        return max_area;
    }

    int largestRectangleArea(vector<int> heights){
        int max_area = 0, last_ind_popped = 0, area;

        pair<int, int> ind_val(0, heights[0]);

        stack<pair<int, int>> st;
        st.push(ind_val);

        for(int i = 1; i < heights.size(); i++){
            int curr_height = heights[i];

            if(curr_height < st.top().second){
                while(!st.empty() && curr_height < st.top().second ){

                    int height = st.top().second, ind = st.top().first;

                    area = height * (i - ind);
                    max_area = max(max_area, area);

                    last_ind_popped = ind;
                    st.pop();
                }

                ind_val = {last_ind_popped, curr_height};
                st.push(ind_val);
            }
            else{
                ind_val = {i, curr_height};
                st.push(ind_val);
            }
        }
        
        int sz = heights.size();

        while(!st.empty()){
            int height = st.top().second, ind = st.top().first;

            area = ((sz - ind) * height);

            max_area = max(max_area, area);
            st.pop();
        }
        return max_area;
    }
};