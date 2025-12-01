class Solution {
public:
    bool check(long long int time, int n, vector<int>& batteries){
        long long int contri = 0;
        for(int b : batteries){
            contri+=min(time, 1LL * b);
            if(contri >= n * time){
                return true;
            }
        }
        return false;
    }

    long long maxRunTime(int n, vector<int>& batteries) {
        long long int res = 0;
        long long int l = 0;
        long long int h = 1e14;
        while(l <= h){
            long long int mid = (l + h) / 2;
            if(check(mid, n, batteries)){
                l = mid + 1;
                res = max(mid, res);
            }else{
                h = mid - 1;
            }
        }
        return res;
    }
};
