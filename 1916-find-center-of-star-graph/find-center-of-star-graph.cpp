class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> freq(n+2, 0);
        for(int i=0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            freq[u]++;
            freq[v]++;
        }

        for(int i=1; i<=n+1; i++) {
            if(freq[i] >= n) {
                return i;
            }
        }
        return -1;
    }
};