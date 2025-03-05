class Solution {
    int find(int u, vector<int> &parent) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = find(parent[u], parent);
    }

    void Union(int u, int v, vector<int> &parent, vector<int> &rank) {
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);

        if(parent_u == parent_v) {
            return;
        }

        if(rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        }
        else if(rank[parent_u] < rank[parent_v]) {
            parent[parent_u] = parent_v;
        }
        else {
            parent[parent_v] = parent_u;
            rank[parent_u]++;
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i=0; i<n; i++) {
            parent[i] = i;
        }

        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int r1 = stones[i][0];
                int c1 = stones[i][1];
                int r2 = stones[j][0];
                int c2 = stones[j][1];

                if(r1 == r2 || c1 == c2) {
                    Union(i, j, parent, rank);
                }
            }
        }

        int grp = 0;
        for(int i=0; i<n; i++) {
            if(parent[i] == i) {
                grp++;
            }
        }
        return n - grp;
    }
};