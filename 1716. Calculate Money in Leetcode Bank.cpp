class Solution {
public:
    int totalMoney(int n) {
        int cnt = 0;
        int week = 1;
        
        while(n > 0){
           for(int i = 0; i < min(n, 7); i++){
                cnt += i + week;
            }
            n = n - 7;      // update n for next week
            week++;
        }
        return cnt;
    }
};
