class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string no = "123456789";
        vector<int>res;
        string l = to_string(low);
        string h = to_string(high);
        for(int i = l.size(); i <= h.size(); i++){
            for(int j = 0; j <= 9 - i; j++){
                string s = no.substr(j, i);
                int num = stoi(s);
                if(num >= low && num <= high){
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};
