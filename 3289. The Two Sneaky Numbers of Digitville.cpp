class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>res;
        unordered_map<int,int>cnt;
        for(int i = 0; i < nums.size(); i++){
            cnt[nums[i]]++;
        }
        for(auto ele : cnt){
            if(ele.second == 2){
                res.push_back(ele.first);
            }
        }
        return res;
    }
};
