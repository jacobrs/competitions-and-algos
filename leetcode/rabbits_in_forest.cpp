#include <vector>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int nums[1000] = {0};
        int sum = 0;
        for(int i : answers){
            if(nums[i] == 0){
                nums[i] = i;
                sum += i + 1;
            }else{
                nums[i]--;
            }
        }
        return sum;
    }
};
