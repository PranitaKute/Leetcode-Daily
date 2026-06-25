class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>res(nums.size());
        for(int i = 0; i < nums.size(); ++i){
            int cur = 0;
            for(int j = i; j < nums.size(); ++j){
                res[cur++] = nums[j];
            }
            for(int j = 0; j < i; ++j){
                res[cur++] = nums[j];
            }
            bool sorted = true;
            for(int j = 0; j < nums.size() - 1; ++j){
                if(res[j] > res[j + 1]){
                    sorted = false;
                    break;
                }
            }
            if(sorted){
                return true;
            }
        }
        return false;
    }
};
