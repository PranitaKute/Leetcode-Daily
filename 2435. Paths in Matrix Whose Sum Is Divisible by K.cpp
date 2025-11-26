class Solution {
public:
    int mod = 1e9 + 7 ;
    vector<vector<vector<int>>>dp;
    int fun(vector<vector<int>>& grid , int r , int c , int rem , int k){
        int m = grid.size();
        int n = grid[0].size();

        if(r == m-1 && c == n-1){
            if((grid[r][c] + rem)%k == 0){
                return 1;
            }
            return 0;
        }

        if(r >= m || c >= n){
            return 0;
        }

        if(dp[r][c][rem] != -1){
            return dp[r][c][rem];
        }

        return dp[r][c][rem] = (fun(grid , r+1 , c , (rem + grid[r][c]%k)%k , k)%mod
                                     + fun(grid , r , c+1 , (rem + grid[r][c]%k)%k , k)%mod)%mod;

    }
    
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        dp.assign(m, vector<vector<int>>(n, vector<int>(51, -1)));
        return fun(grid , 0 , 0 , 0 , k);
    }
};
