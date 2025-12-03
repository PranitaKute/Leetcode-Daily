class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        vector<int>arr;
        for(int n : nums){
            if(n == 0){
                arr.clear();
                continue;
            }
            while(!arr.empty() && arr.back() > n)
                arr.pop_back();
            
            if(arr.empty() || arr.back() < n){
                arr.push_back(n);
                cnt++;
            }
        }
        return cnt;
    }
};
