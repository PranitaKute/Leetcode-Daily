class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
           vector<int>res;
           int cnt = 1;
           for(int i = 0; i <= nums.size() - k; i++){
            unordered_map<int,int>freq;
            for(int j = i; j < i + k; j++){
                freq[nums[j]]++;
            }
            priority_queue<pair<int,int>>pq;
            for(auto f : freq){
                pq.push({f.second, f.first});
            }
            int min = 0;
            int temp = x;
            while(pq.size() > 0 && temp--){
                min += (pq.top().second)*(pq.top().first);
                pq.pop();
            }
            if(cnt <= nums.size() - k + 1){
                res.push_back(min);
                cnt++;
            }
            else 
                break;
           }
        return res;
    }
};
