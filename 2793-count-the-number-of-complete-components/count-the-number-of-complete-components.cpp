class Solution {
    void bfs(unordered_map<int, vector<int>> &adj, vector<int> &visited, int u, int &nodes, int &edges) {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            nodes++;
            edges += adj[node].size();
            for(int &v : adj[node]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
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
                bfs(adj, visited, i, nodes, edges);
                if((edges) == (nodes * (nodes - 1))) {
                    result++;
                }
            }
        }
        return result;
    }
};