class Solution {
    
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
        queue<int> q;
        q.push(source);
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(node == destination) {
                return true;
            }

            for(int &v : adj[node]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return false;
    }
};