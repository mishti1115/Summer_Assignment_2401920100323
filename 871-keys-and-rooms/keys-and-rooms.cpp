class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int>& visited, int i) {
        visited[i] = 1;

        for(int key : rooms[i]) {
            if(!visited[key]) {
                dfs(rooms, visited, key);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        vector<int> visited(n, 0);

        dfs(rooms, visited, 0);

        for(int i = 0; i < n; i++) {
            if(!visited[i])
                return false;
        }

        return true;
    }
};