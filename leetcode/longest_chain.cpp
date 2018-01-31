#include <vector>

using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        bool taken[pairs.size()] = {false};
        int cache[pairs.size()] = {0};
        return _helper(pairs, taken, cache, 0, INT_MIN);
    }

    int _helper(vector<vector<int>>& pairs, bool* taken, int *cache, int size, int tail) {
        int i = 0;
        int max = 0;
        for(auto p: pairs){
            int res = 0;
            if(!taken[i] && p.at(0) > tail){
                if(cache[i]){
                    res = cache[i];
                }
                else {
                    taken[i] = true;
                    cache[i] = _helper(pairs, taken, cache, 1 + size, p.at(1)) - size;
                    taken[i] = false;
                    res = cache[i];
                }
            }
            if(res > max){
                max = res;
            }
            i++;
        }
        return max + size;
    }
};