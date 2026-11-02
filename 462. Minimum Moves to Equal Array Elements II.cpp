class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int mid = nums[nums.size() / 2];
        for(int i : nums){
            cnt += abs(i - mid);
        }
        return cnt;
    }
};
