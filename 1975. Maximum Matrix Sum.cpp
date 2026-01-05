class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // int c = matrix[0].size();
        int cnt = 0;
        long sum = 0;
        long smallest = INT_MAX;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] < 0){
                    cnt++;
                }
                long val = abs(matrix[i][j]);
                smallest = min(smallest, val);
                sum += val;
            }
        }
        if(cnt % 2 != 0){
            sum -= 2 * smallest;
            return sum;
        }
        
        return sum;
    }
};
