class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        
        int maxLen = 0;
        for(int i = 0; i < nums.size(); ++i){
            unordered_set<int>Even;
            unordered_set<int>Odd;
            for(int j = i; j < nums.size(); ++j){
                if(nums[j] % 2 == 0){
                    Even.insert(nums[j]);
                }
                else{
                    Odd.insert(nums[j]);
                }
                if(Even.size() == Odd.size()){
                    maxLen = max(maxLen, j - i + 1);
                }
                // else{
                    // maxLen = max(Even.size(), Odd.size());
                // }
            }
            
        }
        return maxLen;
    }
};
