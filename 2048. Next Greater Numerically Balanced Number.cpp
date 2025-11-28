class Solution {
public:
    int nextBeautifulNumber(int n) {
        // 0 < n < 10^6
        for(int i = n + 1; i <= 1224444; i++){
            int x = i;
            bool flag = true;
            vector<int>count(10,0);
            while(x){
                int m = x % 10;
                count[m]++;
                x = x / 10;
            }
            for(int j = 0; j < 10; j++){
                if(count[j] != 0 && count[j] != j){
                    flag = false;
                }
            }
            if(flag){
                return i;
            }
        // 1224444 is just above 10^6
        }
        return 0;
    }
};
