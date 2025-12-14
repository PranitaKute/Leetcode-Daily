class Solution {
public:
    int numberOfWays(string corridor) {
        vector<int>seats;
        const int MOD = 1e9 + 7;
        for(int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S')
                seats.push_back(i);
        }
        if (seats.size() % 2 != 0){
            return 0;
        }
        long long res = 1;
        for(int i = 2; i < seats.size(); i += 2) {
            res = (res * (seats[i] - seats[i - 1])) % MOD;
        }
        if (seats.size() < 2 || seats.size() % 2 != 0){
            return 0;
        }
        return res;
    }
};
