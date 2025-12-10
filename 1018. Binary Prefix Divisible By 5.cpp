class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>res;
        long long cur = 0;
        for(int i = 0; i < nums.size(); i++){
            cur = ((cur << 1) + nums[i]) % 5;
            res.push_back(cur % 5 == 0);
        }
        return res;
    }
};
