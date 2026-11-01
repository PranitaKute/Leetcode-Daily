class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int min = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > min){
                cnt += nums[i] - min;
            }
        }
        return cnt;
    }
};
