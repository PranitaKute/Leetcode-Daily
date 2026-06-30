class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = size(nums);
        int n1 = INT_MAX, n2 = INT_MAX;
        if(n == 3){
            return nums[0] + nums[1] + nums[2];
        }
        for(int i = 1; i < n; i++){
            int x = nums[i];
            if(x < n1){
                n2 = n1;
                n1 = nums[i];
            }
            else if(x < n2){
                n2 = nums[i];
            }
        }
        return nums[0] + n1 + n2;
    }
};
