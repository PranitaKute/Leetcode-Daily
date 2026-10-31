class Solution {
public:
    void count(vector<vector<int>>& grid, int i, int j){
        int n = grid.size(), m = grid[0].size(); 
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 1){
            return;
        }
        grid[i][j] = 1;
        count(grid, i + 1, j);
        count(grid, i - 1, j);
        count(grid, i, j + 1);
        count(grid, i, j - 1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++){
            count(grid, i, 0);
            count(grid, i, m - 1);
        }
        for(int j = 0; j < m; j++){
            count(grid, 0, j);
            count(grid, n - 1, j);
        }
        int cnt = 0;
        for(int i = 1; i < n - 1; i++){
            for(int j = 1; j < m - 1; j++){
                if(grid[i][j] == 0){
                    cnt++;
                    count(grid, i, j);
                }
            }
        }
        return cnt;
    }
};
