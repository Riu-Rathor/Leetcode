class Solution {
    int dfs(int curr, unordered_map<int, vector<int>> &adj, int k, int currNodeParent) {
        if(k < 0) return 0;

        int count = 1;
        for(int &ngbr : adj[curr]) {
            if(ngbr != currNodeParent) {
                count += dfs(ngbr, adj, k-1, curr);
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
            result[i] = dfs(i, adj, k, -1);
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