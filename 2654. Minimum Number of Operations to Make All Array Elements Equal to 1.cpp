class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cntOne = 0; //if nums has atleast one '1', requires at most n − num1 operations
        int minlen = INT_MAX;
        for(int num : nums){
            if(num == 1){
                cntOne += 1;
            }
        }
        if(cntOne > 0){
            return nums.size() - cntOne;
        }
        for(int i = 0; i < nums.size(); i++){
            int val = 0;
            for(int j = i; j < nums.size(); j++){
                val = gcd(val, nums[j]);
                if(val == 1){
                    minlen = min(minlen, j - i + 1);
                    break;
                }
            }
        }

        return minlen == INT_MAX ? -1 : minlen + nums.size() - 2;
    }
};
