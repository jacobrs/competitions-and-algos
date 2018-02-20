#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int diff = 0;

        for(int i = 0; i < nums.size(); i++){
            bitset<31> b1(nums[i]);
            for(int j = i+1; j < nums.size(); j++){
                bitset<31> b2(nums[j]);
                diff += (b1 ^ b2).count();
            }
        }

        return diff;

    }
};