class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        // int cnt = 0;
        // int mCnt = 0, nCnt = 0;
        for(const string& s : strs){
            int zeros = 0, ones = 0;
            for(char c : s){
                if(c == '0'){
                    zeros++;
                }
                else{
                    ones++;
                }
            }
            for(int i = m; i >= zeros; --i){
                for(int j = n; j >= ones; --j){
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }
        //     if(mCnt <= m && nCnt <= n){
        //         cnt++;
        //         m -= mCnt;
        //         n -= nCnt;
        //     }
        // }
        return dp[m][n];
    }
};
