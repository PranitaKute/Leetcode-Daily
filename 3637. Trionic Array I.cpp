class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        for(int i = 1; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size() - 1; j++){
                bool p = true;
                bool q = true;
                bool r = true;
                for(int k = 0; k < i; k++){
                    if(nums[k] >= nums[k + 1]){
                        p = false;
                    }
                }
                for(int k = i; k < j; k++){
                    if(nums[k] <= nums[k + 1]){
                        q = false;
                    }
                }
                for(int k = j; k < nums.size() - 1; k++){
                    if(nums[k] >= nums[k + 1]){
                        r = false;
                    }
                }
                if(p & q & r){
                    return true;
                }
            }
        }

        return false;
    }
};
