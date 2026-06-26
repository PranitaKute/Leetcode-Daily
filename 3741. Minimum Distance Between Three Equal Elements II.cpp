class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> value;
        for (int i = 0; i < nums.size(); ++i) {
            value[nums[i]].push_back(i);
        }
        int min_dist = INT_MAX;
        for (auto const& [val, indices] : value) {
            if (indices.size() >= 3) {
                for (int i = 0; i < indices.size() - 2; ++i) {
                    int dist = 2 * (indices[i + 2] - indices[i]);
                    min_dist = min(min_dist, dist);
                }
            }
        }
        if (min_dist == INT_MAX) {
            return -1;
        }
        return min_dist;
    }
};
