class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int max_h = 1, max_v = 1;
        int curr_h = 1, curr_v = 1;
        for(int i = 1; i < hBars.size(); i++){
            if(hBars[i] == hBars[i - 1] + 1){
                curr_h += 1;
            }
            else{
                curr_h = 1;
            }
            max_h = max(max_h, curr_h);
        }
        for(int i = 1; i < vBars.size(); i++){
            if(vBars[i] == vBars[i - 1] + 1){
                curr_v += 1;
            }
            else{
                curr_v = 1;
            }
            max_v = max(max_v, curr_v);
        }
        int len = min(max_v, max_h) + 1;

        return len * len;

    //  return 4;   // Just for fun :)
    }
};
