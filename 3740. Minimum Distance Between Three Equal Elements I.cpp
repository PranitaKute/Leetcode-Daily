class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int min_dist = INT_MAX;
        bool f = false;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                for(int k = j + 1; k < nums.size(); k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        int dist = abs(i - j) + abs(j - k) + abs(k - i);
                        min_dist = min(dist, min_dist);
                        f = true;
                    }
                }
            }
        }
        return f ? min_dist : -1;
    }
};
