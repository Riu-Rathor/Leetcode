class Solution {

    void dfs(int u, vector<int> &visited, unordered_map<int, vector<int>> &adj, stack<int> &st, bool &cycle) {
        visited[u] = 1;
        for(int &v : adj[u]) {
            if(visited[v] == 0) {
                dfs(v, visited, adj, st, cycle);
            }
            else if(visited[v] == 1) {
                cycle = true;
                return;
            }
        }
        visited[u] = 2;
        st.push(u);
    } 

    vector<int> topoSort(vector<vector<int>> &edges, int k) {
        // make adjacency list
        unordered_map<int, vector<int>> adj;
        stack<int> st;
        vector<int> order;
        vector<int> visited(k+1, 0);
        bool cycle = false;

        for(vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        for(int i=1; i<=k; i++) {
            if(visited[i] == 0) {
                dfs(i, visited, adj, st, cycle);
                if(cycle) {
                    return {};
                }
            }
        }
        while(!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        return order;

    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> topoRow = topoSort(rowConditions, k);
        vector<int> topoCol = topoSort(colConditions, k);


        if(topoRow.empty() || topoCol.empty()) {
            return {};
        }

        vector<vector<int>> result(k, vector<int> (k, 0));
        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                if(topoRow[i] == topoCol[j]) {
                    result[i][j] = topoRow[i];
                }
            }
        }
        return result;
    }
};