#include <vector>

class Solution {
public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        int max = 0;
        int i = 0; int j = INT_MIN;

        int run = 0;
        while(i < nums.size()){
            if(nums[i] > j){
                run++;
                j = nums[i];
                i++;
            }else{
                if(run > max){
                    max = run;
                }
                run = 0;
                j = INT_MIN;
            }
        }

        if(run > max){
            max = run;
        }

        return max;
    }
};