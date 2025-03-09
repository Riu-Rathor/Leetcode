class Solution {
    bool dfs(unordered_map<int, vector<int>> &adj, int src, int dest, vector<bool> &visited) {
        visited[src] = true;
        if(src == dest) {
            return true;
        }

        for(int &v : adj[src]) {
            if(!visited[v]) {
                if(dfs(adj, v, dest, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj;
        for(vector<int> &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs(adj, source, destination, visited);
    }
};