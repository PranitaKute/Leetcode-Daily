class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int cnt = 0;
        bool flag = true;
        vector<int>pos;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                pos.push_back(i);
            }
        }
        for(int i = 1; i < pos.size(); i++){
            int diff = 0;
            diff = pos[i] - pos[i - 1];
            if(diff >= k + 1){
                //k + 1 - cause a difference of 1 means they are adjacent
                continue;
            }
            else{
                flag = false;
                break;
            }
        }
        return flag;
    }
};
