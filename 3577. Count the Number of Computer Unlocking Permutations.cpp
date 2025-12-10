class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        if(*min_element(complexity.begin() + 1, complexity.end()) <= complexity[0]){
            return 0;
        }
        
        int res = 1;
        int MOD = 1000000007;
        for(int i = 2; i < complexity.size(); i++){
            res = static_cast<long long>(res) * i % MOD;
        }

        return res;
    }
};
