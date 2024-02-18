class Solution {

    void dfs(vector<vector<int>> &rooms, int src, vector<bool> &visited) {
        visited[src] = true;
        for(int &node: rooms[src]) {
            if(!visited[node]) {
                dfs(rooms, node, visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n);
        visited[0] = true;
        dfs(rooms, 0, visited);

        for(bool vis : visited) {
            if(vis == false) {
                return false;
            }
        }
        return true;
    }
};