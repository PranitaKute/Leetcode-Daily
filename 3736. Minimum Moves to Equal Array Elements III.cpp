class Solution {
public:
    int minMoves(vector<int>& nums) {
        auto max_i = max_element(nums.begin(), nums.end());
        int max = *max_i;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < max){
                cnt += max - nums[i];
            }
        }
        return cnt;
    }
};
