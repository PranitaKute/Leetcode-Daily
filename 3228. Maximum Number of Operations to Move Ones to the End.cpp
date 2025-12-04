class Solution {
public:
    int maxOperations(string s) {
        int cnt_ones = 0;
        int operation = 0;
        for (int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                while((i + 1) < s.length() && s[i + 1] == '0'){
                    i++;
                }
                operation += cnt_ones;
            }
            else{
               cnt_ones++; 
            }
        }
        return operation;
    }
};
