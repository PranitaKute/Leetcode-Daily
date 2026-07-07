class Solution {
public:
    long long removeZeros(int n) {
        string s = to_string(n);
        string res = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] != '0'){
                res.push_back(s[i]);
            }
            else{
                if(s.length() == 1){
                    res.push_back('0');
                }
            }
        }
        long long ans = stoll(res);
        return ans;
    }
    long long sumAndMultiply(int n) {
        long long concat = removeZeros(n);
        long long sum = 0;
        while(n != 0){
            int last = n % 10;
            sum += last;
            n /= 10;
        }
        return sum * concat;
    }
};
