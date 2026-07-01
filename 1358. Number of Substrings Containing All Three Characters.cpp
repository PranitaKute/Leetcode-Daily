class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> mp;
        int cnt = 0;
        int no = 0, i = 0, j = 0;

        while(j < s.size()){
            mp[s[j]]++;

            if(s[j] == 'a'){
                no = no | 1;
            }
            else if (s[j] == 'b'){
                no = no | 2;
            }
            else{
                no = no | 4;
            }
            
            while(no == 7){
                cnt += (s.size() - j);
                mp[s[i]]--;

                if(s[i] == 'a' && mp[s[i]] == 0){
                    no = 6;
                }
                if(s[i] == 'b' && mp[s[i]] == 0){
                    no = 5;
                }
                if(s[i] == 'c' && mp[s[i]] == 0){
                    no = 3;
                }
                i++;
            }
            j++;
        }

        return cnt;
    }
};
