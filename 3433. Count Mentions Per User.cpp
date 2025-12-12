class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<vector<int>>offline(numberOfUsers);
        vector<int>here;
        vector<int>res(numberOfUsers, 0);
        int cnt = 0;

        for(auto &e : events){
            if(e[0] == "OFFLINE"){
                int ind = stoi(e[2]);
                int time = stoi(e[1]);
                offline[ind].push_back(time);
            }
            else{
                int time = stoi(e[1]);
                if(e[2] == "HERE"){
                    here.push_back(time);
                }
                else if(e[2] == "ALL"){
                    cnt++;
                }
                else{
                    string s = e[2];
                    stringstream ss(s);
                    string word = "";
                    while(ss >> word){
                        string sub = word.substr(2);
                        int id = stoi(sub);
                        res[id]++;
                    }
                }
            }
        }
        sort(here.begin(), here.end());
        for(auto &o : offline){
            sort(o.begin(), o.end());
        }
        for(int i = 0; i < numberOfUsers; i++){
            auto &o = offline[i];
            res[i] += (int)here.size();
            for(auto &val : o){
                auto ind = lower_bound(here.begin(), here.end(), val);
                auto ind2 = lower_bound(here.begin(), here.end(), val + 60);
                res[i] -= (int)(ind2 - ind);
            }
        }
        for(auto &val : res){
            val += cnt;
        }

        return res;
    }
};
