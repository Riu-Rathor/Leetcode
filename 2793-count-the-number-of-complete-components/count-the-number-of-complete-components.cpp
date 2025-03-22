class Solution {
     void Union(int u, int v, vector<int> &parent, vector<int> &size) {
        int parent_u = find(u, parent);
        int parent_v = find(v, parent);

        if (parent_u == parent_v) return;

        if (size[parent_u] > size[parent_v]) {
            parent[parent_v] = parent_u;
            size[parent_u] += size[parent_v];
        } else {
            parent[parent_u] = parent_v;
            size[parent_v] += size[parent_u];
        }
    }
    int find(int i, vector<int> &parent) {
        if(i == parent[i]) {
            return i;
        }

        return parent[i] = find(parent[i], parent);
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> size(n);
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        for(vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            Union(u, v, parent, size);
        }

        for(vector<int> &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int root = find(u, parent);
            mp[root]++;
        }

        int result = 0;
        for(int i=0; i<n; i++) {
            if(find(i, parent) == i) {
                int v = size[i];
                int e = mp[i];

                if((v*(v-1)/2) == e) {
                    result++;
                }
            }
        }
        return result;
    }

};