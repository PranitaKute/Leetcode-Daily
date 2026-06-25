class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() -1;
        while(low < high){
            int mid = (high + low) / 2;
            if(nums[mid] > nums[high]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];

        // sort(nums.begin(), nums.end());
        // return nums[0];
        // // just for fun :)
    }
};
