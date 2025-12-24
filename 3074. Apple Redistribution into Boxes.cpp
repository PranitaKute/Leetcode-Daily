class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());

        int n = 0;
        while(sum > 0){
            sum -= capacity[n];
            n += 1;
        }

        return n;
    }
};
