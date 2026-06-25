class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        int low = 0, high = nums.size() - 1;
        
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                res = mid;
                return res;
            }
            if(nums[mid] >= nums[low]){
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;      // move to left
                }
                else{
                    low = mid + 1;
                }
            }
            else{
                if(target > nums[mid] && target <= nums[high]){
                    low = mid + 1;      // move to right
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return res;
    }
};
