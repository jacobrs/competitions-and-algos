#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {

        unordered_map<int, int> map;
        int wall_width = 0;

        for(auto row: wall) {
            int total = 0;
            for(auto brick: row) {
                total += brick;
                map[total] ++;
            }
            wall_width = total;
        }

        int max_occ = 0;
        int level = 0;
        int rows = wall.size();
        bool split = false;

        for ( auto it = map.begin(); it != map.end(); ++it ) {
            if (it->second > max_occ && it->first < wall_width) {
                level = it->first;
                max_occ = it->second;
                split = true;
            }
        }

        //std::cout << level << ":" << max_occ << std::endl;
        return (!split) ? rows : rows - max_occ;

    }
};