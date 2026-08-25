class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>check(nums.begin(), nums.end());      // to check if preesent
        int mul = 1;
        for(int i = 1; ; ++i){
            mul = i * k;
            if(check.find(mul) == check.end()){
                return mul;
            }
        }
        return mul;
    }
};
