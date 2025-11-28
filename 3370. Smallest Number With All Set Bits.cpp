class Solution {
public:
    int smallestNumber(int n) {
        vector<int> bin;
        while(n > 0){
            int bit = n & 1;
            bin.push_back(bit);
            n >>= 1;
        }
        reverse(bin.begin(), bin.end());
        // return bin;
        for(size_t i = 0; i < bin.size(); i++){
            if(bin[i] == 0){
                bin[i] = 1;
            }
        }
        // int num = bin;
        int dec_value = 0;
        int power = 0;
        // int temp = num;
        for(int i = bin.size() - 1; i >= 0; --i){
            if(bin[i] == 1){
                dec_value += (1 << power);
            }
            power++;
        }
        return dec_value;
    }
};
