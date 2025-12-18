class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        // long long res = 0;
        vector<long long>profit(n + 1, 0);
        vector<long long>price(n + 1, 0);
        for(int i = 0; i < n; i++){
            profit[i + 1] = profit[i] + (long long)prices[i] * strategy[i];
            price[i + 1] = price[i] + prices[i];

        }
        long long res = profit[n];
        for(int i = k - 1; i < n; ++i){
            long long leftprofit = profit[i - k + 1];
            long long rightprofit = profit[n] - profit[i + 1];
            long long changeprofit = price[i + 1] - price[i - k / 2 + 1];
            res = max(res, leftprofit + rightprofit + changeprofit);
        }
        return res;
    }
};
