// Question Link : https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/description/?envType=daily-question&envId=2025-10-15

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int currCnt = 1, prevMax = 0;
        int res = 0;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i - 1]){          // check if current is greater than previous
                ++currCnt;      
            }
            else{
                prevMax = currCnt;                  // update previous max 
                currCnt = 1;
            }
            
            res = max(res, min(prevMax, currCnt));  //prevMax -> previous subarray, currCnt -> current max
            res = max(res, currCnt / 2);            
        }
        return res;

    }
};
