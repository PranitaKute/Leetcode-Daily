class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0){
            return 0;
        }
        int p = 0, current = 1;
        while(current * 2 <= n){
            current *= 2;
            p++;
        }
        return (1 << (p + 1)) - 1 - minimumOneBitOperations(n ^ current);

    }
};
