class Solution {
    void dfs(vector<vector<int>> &grid, int m, int n, int i, int j, int &perimeter) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
            perimeter++;
            return;
        }

        if(grid[i][j] == -1) {
            return;
        }
        grid[i][j] = -1;

        dfs(grid, m, n, i+1, j, perimeter);
        dfs(grid, m, n, i-1, j, perimeter);
        dfs(grid, m, n, i, j+1, perimeter);
        dfs(grid, m, n, i, j-1, perimeter);
    }

    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(vector<vector<int>>& grid, int m, int n, int i, int j, int &perimeter) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            for(auto &dir : direction) {
                int i_ = it.first + dir[0];
                int j_ = it.second + dir[1];

                if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == 0) {
                    perimeter++;
                }
                else if(grid[i_][j_] == -1) {
                    continue;
                }
                else {
                    q.push({i_, j_});
                    grid[i_][j_] = -1;
                }
            }
        }
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int perimeter = 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    bfs(grid, m, n, i, j, perimeter);
                    return perimeter;
                }
            }
        }
        return -1;
    }
};