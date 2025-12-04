class Solution {
public:
    int countCollisions(string directions){
        int l = 0, r = directions.size() - 1;
        while(l < directions.size() && directions[l] == 'L'){
            l++;
        }
        while(r >= l && directions[r] == 'R'){
            r--;
        }

        int ans = 0;
        for(int i = l; i <= r; i++){
            if(directions[i] != 'S'){
                ans++;
            }
        }


        return ans;
    }
};
