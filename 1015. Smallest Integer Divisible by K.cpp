class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int cur = 1;
        int n = 1;
        vector<int>prev;
        while(cur % k != 0){
            // if cur in prev
            for(int i = 0; i < prev.size(); i++){
                if(prev[i] == cur){
                    return -1;
                }
            }
            prev.push_back(cur);
            cur = 10 * (cur % k) + 1;
            n++;
        }
        return n;
    }
};
