#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int j = 0;
        int l = k-1;
        double sum = 0;
        for(int i = j; i < k; i++){
            sum += nums[i];
        }
        double max = sum/(double)k;

        while(l < nums.size() - 1){
            sum -= (double)nums[j++];
            sum += (double)nums[++l];
            if(sum/(double)k > max){
                max = sum/k;
            }
        }

        return max;
    }
};
