class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int>freq;
        int l = 0, res = 0;
        for(int r = 0; r < nums.size(); r++){
            freq[nums[r]]++;
            while(freq[nums[r]] > k){
                freq[nums[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
