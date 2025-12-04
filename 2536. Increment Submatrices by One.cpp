class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>nums(n, vector<int>(n,0));
        for(int i = 0; i < queries.size(); i++){
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];
            for(int row = r1; row <= r2; row++){
                for(int col = c1; col <= c2; col++){
                    nums[row][col] += 1;
                }
            }
        }
        return nums;
    }
};
