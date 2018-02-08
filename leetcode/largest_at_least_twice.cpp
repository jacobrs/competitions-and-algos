#include <vector>

using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int secondLargestId = 0;
        int largestId = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[largestId]){
                secondLargestId = largestId;
                largestId = i;
            }else if(nums[i] > nums[secondLargestId] || largestId == secondLargestId){
                secondLargestId = i;
            }
        }

        if(nums[largestId] >= nums[secondLargestId] * 2) {
            return largestId;
        } else if (largestId == secondLargestId){
            return largestId;
        }
        return -1;
    }
};
