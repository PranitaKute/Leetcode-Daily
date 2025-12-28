class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        int m = grid.size();
        int n = grid[0].size();
        int row = 0, col = n - 1;

        while(row < m && col >= 0){
            if(grid[row][col] < 0){
                cnt += (m - row);
                col--;  // move left
            }
            else{
                row++;  // move downwards
            }
        }
        return cnt;
    }
};
