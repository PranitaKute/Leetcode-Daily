class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0, n = points.size();
        for(int i = 0; i < n - 1; i++){
            int curr_x = points[i][0], curr_y = points[i][1];
            int target_x = points[i + 1][0], target_y = points[i + 1][1];
            res += max(abs(target_x - curr_x), abs(target_y - curr_y));
        }
        return res;
    }
};
