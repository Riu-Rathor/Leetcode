class Solution {
    

    void dfs(int u, int prev, unordered_map<int, vector<int>> &adj, vector<int> &ans) {
        ans.push_back(u);
        for(int v : adj[u]) {
            if(v != prev) {
                dfs(v, u, adj, ans);
            }
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        vector<int> ans;
        for(int i=0; i<adjacentPairs.size(); i++) {
            int u = adjacentPairs[i][0];
            int v = adjacentPairs[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int startPoint = -1;
        for(auto i : adj) {
            if(i.second.size() == 1) {
                startPoint = i.first;
            }
        }


        dfs(startPoint, INT_MIN, adj, ans);
        return ans;
    }
};