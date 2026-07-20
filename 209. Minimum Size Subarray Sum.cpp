class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int right = 0;
        int minimum = INT_MAX;
        for(int left = 0; left < nums.size(); left++){
            sum += nums[left];
            while(sum >= target){
                minimum = min(minimum, (left - right + 1));
                sum -= nums[right];
                right++;
            }
        }
        if(minimum == INT_MAX)
            return 0;

        return minimum;
    }
};
