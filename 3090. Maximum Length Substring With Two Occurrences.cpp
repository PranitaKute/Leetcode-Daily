class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, res = 0;
        array<int, 26> cnt{};
        for(int r = 0; r < s.length(); r++){
            int ch = s[r] - 'a';
            cnt[ch]++;
            while(cnt[ch] > 2){
                const int ch2 = s[l] - 'a';
                cnt[ch2]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
