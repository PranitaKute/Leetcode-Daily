class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());       // sort descending
        int t = 0;
        long long sum = 0;
        for(int i = 0; i < k; i++){
            sum += max(happiness[i] - t, 0);
            t++;
        }
        return sum;   
    }
};
