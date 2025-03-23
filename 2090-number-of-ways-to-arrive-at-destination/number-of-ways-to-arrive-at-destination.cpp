class Solution {
    typedef pair<long long, int> P;
    int MOD = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<long long> result(n, LLONG_MAX);
        vector<int> pathCount(n, 0);

        result[0] = 0;
        pathCount[0] = 1;
        pq.push({0, 0});

        while(!pq.empty()) {
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto &vec : adj[node]) {
                int ngbr = vec.first;
                int roadTime = vec.second;

                if(time + roadTime < result[ngbr]) {
                    result[ngbr] = time + roadTime;
                    pq.push({result[ngbr], ngbr});
                    pathCount[ngbr] = pathCount[node];
                }
                else if(time + roadTime == result[ngbr]) {
                    pathCount[ngbr] = (pathCount[ngbr] + pathCount[node]) % MOD;
                }
            }
        }

        return pathCount[n-1];

    }
};