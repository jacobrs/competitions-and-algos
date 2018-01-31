#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int last = -1;
        int beforeLast = INT_MIN;
        bool swapped = false;
        int i = 0;
        bool repeat = false;
        for(auto n: nums){
            if(last == -1){
                last = n;
                i++;
                continue;
            }
            else if(n < last && !swapped){
                if(i < nums.size() - 1){
                    if(n < nums.at(i+1)){
                        if(n < beforeLast && nums.at(i+1) < last) {
                            return false;
                        }
                    }else if(n == nums.at(i+1)){
                        if(repeat){
                            return false;
                        }
                    }
                }
                swapped = true;
            }else if(n < last){
                return false;
            }
            if(last != n){
                beforeLast = last;
                last = n;
                repeat = false;
            }else{
                repeat = true;
            }
            i++;
        }
        return true;
    }
};