class Solution {
    bool isBipartite(unordered_map<int , vector<int>> &adj, int currColor, vector<int> &colors, int node) {
        queue<int> q;
        q.push(node);
        colors[node] = currColor;

        while(!q.empty()) {
            int u = q.front();
            q.pop();
            int currColor = colors[u];
            for(int &v : adj[u]) {
                if(colors[v] == colors[u]) {
                    return false;
                }
                if(colors[v] == -1) {
                    colors[v] = 1 - currColor;
                    q.push(v);
                }            
            }
        }        
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int , vector<int>> adj;
        vector<int> colors(n+1, -1);

        for(vector<int> &dislike : dislikes) {
            int u = dislike[0];
            int v = dislike[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; i++) {
            if (colors[i] == -1) {
                if (!isBipartite(adj, 0, colors, i)) {
                    return false;
                }
            }
        }

        return true;
    }
};