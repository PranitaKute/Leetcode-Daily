class Solution {
public:
    const int unGuarded = 0;
    const int guarded = 1;
    const int GUARD = 2;
    const int WALL = 3;

    void rec(int row, int col, vector<vector<int>>& grid, char direction){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size() || grid[row][col] == GUARD || grid[row][col] == WALL){
            return;
        }
        grid[row][col] = guarded;
        if(direction == 'U')rec(row - 1, col, grid, 'U');   //upward
        if(direction == 'D')rec(row + 1, col, grid, 'D');   // downward
        if(direction == 'L')rec(row, col - 1, grid, 'L');   //Left
        if(direction == 'R')rec(row, col + 1, grid, 'R');
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, unGuarded));

        // Mark guards' positions
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = GUARD;
        }

        //wall position
        for(const auto& wall : walls){
            grid[wall[0]][wall[1]] = WALL;
        }

        //guarded cells
        for(const auto& guard : guards){
            rec(guard[0] - 1, guard[1], grid, 'U'); //upward
            rec(guard[0] + 1, guard[1], grid, 'D'); //downward
            rec(guard[0], guard[1] - 1, grid, 'L'); //left
            rec(guard[0], guard[1] + 1, grid, 'R'); //right
        }

            //count unguarded
        int cnt = 0;
        for(const auto& row : grid){
            for(const auto& cell : row){
                if(cell == unGuarded){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
