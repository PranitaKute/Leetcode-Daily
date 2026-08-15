class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        for(int n : nums){
            totalXor ^= n;
        }
        if(totalXor != 0){
            return nums.size();
        }
        for(int n : nums){
            if(n != 0){
                return nums.size() - 1;
            }
        }
        return 0;
    }
};
