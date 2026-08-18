class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int res = -1;
        unordered_map<int, int> mp;
        if(k == nums.size()){
            for(int i = 0; i < nums.size(); i++){
                res = max(res, nums[i]);
            }
            return res;
        }
        for(int i = 0; i <= nums.size() - k; i++){
            int l = k;
            int j = i;
            while(l){
                mp[nums[j]]++;
                j++;
                l--;
            }
        }
        for(auto m : mp){
            int f = m.first;
            int s = m.second;
            if(s == 1){
                res = max(res, f);
            }
        }
        return res;
    }
};
