class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0;
        for(int n : nums){
            res += n;
        }
        return res % k;
    }
};
