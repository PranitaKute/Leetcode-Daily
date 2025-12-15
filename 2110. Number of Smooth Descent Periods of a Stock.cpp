class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long cur;
        long long res = 0;
        for(int i = 0; i < prices.size(); i++){
            cur = 1;
            while(((i + 1) < prices.size()) && (((prices[i + 1] + 1) == prices[i]))){
                cur++;
                i++;
            }
            res += (cur * (cur + 1)) / 2;
        }

        return res;
    }
};
