class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms){

        vector<int> checked(rooms.size(), 0);
        
        checked[0] = 1;

        dfs(rooms, checked, 0);

        for(int room : checked) if(!room) return false;

        return true;
    }

    void dfs(vector<vector<int>>& rooms, vector<int>& checked, int ind){

        vector<int> room = rooms[ind];

        for(int i = 0; i < room.size(); i++){
            if(!checked[room[i]]){
                checked[room[i]] = 1;
                dfs(rooms, checked, room[i]);
            }
        }
    }
};