class Solution {
    void dfs(unordered_map<int, vector<int>> &adj, vector<int> &visited, int u, int &nodes, int &edges) {
        visited[u] = true;
        nodes++;
        edges += adj[u].size();

        for(int &v : adj[u]) {
            if(!visited[v]) {
                dfs(adj, visited, v, nodes, edges);
            }
        }

    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, false);
        int result = 0;

        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                int edges = 0;
                int nodes = 0;
                dfs(adj, visited, i, nodes, edges);
                if((edges / 2) >= (nodes * (nodes - 1) / 2)) {
                    result++;
                }
            }
        }
        return result;
    }
};