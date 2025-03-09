class Solution {
    void dfs(vector<vector<int>>& rooms, int u, unordered_set<int> &st, vector<bool> &visited) {
        visited[u] = true;
        st.insert(u);

        for(int &v : rooms[u]) {
            if(!visited[v]) {
                dfs(rooms, v, st, visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int> st;
        vector<bool> visited(n, false);
        dfs(rooms, 0,  st, visited);
        return st.size() == n;
    }
};