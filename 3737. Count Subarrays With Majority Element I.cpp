class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            long long target_cnt = 0;
            long long len = 0;
            for(int j = i; j < nums.size(); j++){
                // vector<long long>arr;
                len++;
                
               if(nums[j] == target){
                        target_cnt++;
                }
                if(target_cnt > len / 2){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
