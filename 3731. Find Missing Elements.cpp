class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>missing;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() - 1; i++){
            int expected = nums[i] + 1;
            int actual = nums[i + 1];
            while(expected < actual){
                missing.push_back(expected);
                expected++;
            }
        }
        return missing;
    }
};
