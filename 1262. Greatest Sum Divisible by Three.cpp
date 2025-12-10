class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>rem1,rem2;       // rem1 = remainder 1, rem2 = remainder 2
        int total = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 3 == 1){
                rem1.push_back(nums[i]);
            }
            if(nums[i] % 3 == 2){
                rem2.push_back(nums[i]);
            }
            total += nums[i];
        }
        if(total % 3 == 0){
            return total;
        }        
        
        sort(rem1.begin(), rem1.end());
        sort(rem2.begin(), rem2.end());

        if(total % 3 == 1){
            int del1 = rem1.size() >= 1 ? rem1[0] : INT_MAX;
            int del2 = rem2.size() >= 2 ? rem2[0] + rem2[1] : INT_MAX;
            int delnum = min(del1, del2);
            return delnum == INT_MAX ? 0 : total - delnum;
        }
        else if(total % 3 == 2){
            int del1 = rem2.size() >= 1 ? rem2[0] : INT_MAX;
            int del2 = rem1.size() >= 2 ? rem1[0] + rem1[1] : INT_MAX;
            int delnum = min(del1, del2);
            return delnum == INT_MAX ? 0 : total - delnum;
        }

        return 0;
        
    }
};
