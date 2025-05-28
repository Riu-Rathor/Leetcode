class Solution {
    int bfs(int curr, unordered_map<int, vector<int>> &adj, int k, int n) {
        queue<pair<int, int>> q;
        q.push({curr, 0});
        vector<bool> visited(n, false);
        visited[curr] = true;
        int count = 0;

        while(!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            if(d > k) {
                continue;
            }
            count++;
            for(auto &ngbr : adj[node]) {
                if(!visited[ngbr]) {
                    visited[ngbr] = true;
                    q.push({ngbr, d+1});
                }
            }
        }
        return count;
    }
    vector<int> findCount(vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        // adjacency list
        unordered_map<int, vector<int>> adj;
        for(vector<int> &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> result(n);

        for(int i=0; i<n; i++) {
            result[i] = bfs(i, adj, k, n);
        }
        return result;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<int> result1 = findCount(edges1, k);
        vector<int> result2 = findCount(edges2, k-1);

        int maxTargetNodesCount = *max_element(result2.begin(), result2.end());

        for(int i=0; i<n; i++) {
            result1[i] += maxTargetNodesCount;
        }
        return result1;
    }
};