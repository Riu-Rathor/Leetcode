class Solution {

    void djkstra(int n, unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &ans, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        fill(ans.begin(), ans.end(), INT_MAX);
        ans[src] = 0;
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto &neighbour : adj[node]) {
                int adjNode = neighbour.first;
                int d = neighbour.second;

                if((dis+d) < ans[adjNode]) {
                    ans[adjNode] = dis + d;
                    pq.push({dis + d, adjNode});
                }
            }
        }
    }

    int findMinCities(int n, vector<vector<int>> &SPM, int distanceThreshold) {
        int ans = -1;
        int leastReach = INT_MAX;

        for(int i=0; i<n; i++) {
            int countReach = 0;
            for(int j=0; j<n; j++) {
                if(i != j && SPM[i][j] <= distanceThreshold) {
                    countReach++;
                }
            }
            if(countReach <= leastReach) {
                leastReach = countReach;
                ans = i;
            }
        }
        return ans;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<pair<int, int>>> adj;
        int ans = 0;
        int minCities = INT_MAX;
        vector<vector<int>> SPM(n, vector<int>(n, INT_MAX));

        for(int i=0; i<n; i++) {
            SPM[i][i] = 0;
        }

        // creating the adjacency list
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            adj[u].push_back({v, weight});
            adj[v].push_back({u, weight});
        }

        for(int i=0; i<n; i++) {
            djkstra(n, adj, SPM[i], i);
        }

        return findMinCities(n, SPM, distanceThreshold);
    }
};