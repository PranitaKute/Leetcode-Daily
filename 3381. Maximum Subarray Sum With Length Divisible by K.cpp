class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long prefixSum = 0;
        long long maxSum = LLONG_MIN;
        vector<long long>Ksum(k, LLONG_MAX / 2);        // /2 cause half of infinity
        Ksum[k - 1] = 0;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            int rem = i % k;
            if(Ksum[rem] != LLONG_MAX / 2){
                maxSum = max(maxSum, prefixSum - Ksum[rem]);
            }
            Ksum[rem] = min(Ksum[rem], prefixSum);
        }

        return maxSum;
    }
};
