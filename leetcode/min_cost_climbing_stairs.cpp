#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int cache[cost.size()];
        for(int i = 0; i < cost.size(); i++){
            cache[i] = -1;
        }
        return min(_helper(cost, 0, 0, cache), _helper(cost, 1, 0, cache));
    }

    int _helper(std::vector<int>& cost, int curr, int price, int *cache) {
        if(curr >= cost.size()){
            return price;
        }

        if(cache[curr] != -1){
            return cache[curr] + price;
        }

        cache[curr] = min(_helper(cost, curr + 1, price + cost[curr], cache), _helper(cost, curr + 2, price + cost[curr], cache)) - price;
        return cache[curr] + price;

    }

    int min(int i, int j) {
        if(i < j){
            return i;
        }
        return j;
    }
};