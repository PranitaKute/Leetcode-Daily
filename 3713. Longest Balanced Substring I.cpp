class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = 0;
        int n = s.length();
        string temp = s;
        for(int i = 0; i < n; ++i){
            map < char , int >Freq;
            for(int j = i; j < n; ++j){
                char curChar = temp[j];
                Freq[curChar]++;
                bool balanced = true;
                int firstFreq = -1;
                
                if(!Freq.empty()){
                    firstFreq = Freq.begin()->second;
                    
                }

                for(const auto& pair:Freq){
                    if(pair.second != firstFreq){
                        balanced = false;
                        break;
                    }    
                }

                if(balanced){
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
    }
};
