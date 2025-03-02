class Solution {
    vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isSafe(int i, int j, vector<vector<int>>& grid, int m, int n) {
        return (i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 1);
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int freshOranges = 0;
        int minutes = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if(freshOranges == 0) {
            return 0;
        }

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();          

                for(vector<int> &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if(isSafe(new_i, new_j, grid, m, n)) {
                        grid[new_i][new_j] = 2;
                        q.push({new_i, new_j});
                        freshOranges--;
                    }
                }
            }
            minutes++;
        }
        if(freshOranges == 0){
            return minutes - 1;
        }
        return -1;

    }
};