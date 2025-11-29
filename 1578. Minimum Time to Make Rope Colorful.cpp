class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        /*Approach : Iterate through the string of colors, if colors[i] = colors[i + 1], time += neededTime[i]
                     If comsecutive ballons, keep the one which has maximum (neededTime) time */

        for(int i = 1; i < colors.size(); i++){
            if(colors[i - 1] == colors[i]){
                time += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return time;
    }
};
