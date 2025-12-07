class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        bool res = false;
        int n = bits.size();
        int i = 0;
        while(i < n){
            if(bits[i] == 0){
                i++;
                res = true;
            }
            else{
                i += 2;
                res = false;
            }
        }
        return res;
    }
};
