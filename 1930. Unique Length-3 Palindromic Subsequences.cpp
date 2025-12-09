class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        for(int i = 'a'; i <= 'z'; i++){
            char c = i;
            int l = 0;
            int r = s.size() - 1;
            while(l < r && s[l] != c){
                l++;
            }
            while(l < r && s[r] != c){
                r--;
            }
            if(l < r){
                int arr[26]{};
                int cnt = 0;
                for(int j = l + 1; j < r; j++){
                    if(arr[s[j] - 'a'] == 0){
                        arr[s[j] - 'a']++;
                        cnt++;
                    }
                }
                res += cnt;
            }
        }
        return res;
    }
};
