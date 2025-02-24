class Solution {
    bool dfsBob(unordered_map<int, vector<int>> &adj, int node, int time, vector<bool> &visited, unordered_map<int, int> &bobMap) {
        visited[node] = true;
        bobMap[node] = time;

        if(node == 0) {
            return true;
        }

        for(auto &ngbr : adj[node]) {
            if(!visited[ngbr]) {
                if(dfsBob(adj, ngbr, time+1, visited, bobMap)) {
                    return true;
                }
            }
        }
        
        bobMap.erase(node);
        return false;
    }

    void dfsAlice(unordered_map<int, vector<int>> &adj, int node, int time, vector<bool> &visited, int income, int &aliceIncome, vector<int> &amount, unordered_map<int, int> &bobMap) {
        visited[node] = true;
        if(bobMap.find(node) == bobMap.end() || time < bobMap[node]) {
            income += amount[node];
        }
        else if(time == bobMap[node]) {
            income += (amount[node] / 2);
        }

        if(adj[node].size() == 1 && node != 0) {
            aliceIncome = max(aliceIncome, income);
        }

        for(int &ngbr : adj[node]) {
            if(!visited[ngbr]) {
                dfsAlice(adj, ngbr, time+1, visited, income, aliceIncome, amount, bobMap);
            }
        }

    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        int aliceIncome = INT_MIN;

        unordered_map<int, vector<int>> adj;
        for(vector<int> &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // DFS on Bob
        int time = 0;
        vector<bool> visited(n, false);
        unordered_map<int, int> bobMap;
        dfsBob(adj, bob, time, visited, bobMap);

        visited.assign(n, false);
        int income = 0;
        dfsAlice(adj, 0, 0, visited, income, aliceIncome, amount, bobMap);
        return aliceIncome;
    }
};