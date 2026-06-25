class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>left;
        vector<int>right;
        vector<int>same;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot){
                left.push_back(nums[i]);
            }
            else if(nums[i] == pivot){
                same.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }
        // sort(right.begin(), right.end());
        left.insert(left.end(), same.begin(), same.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};
