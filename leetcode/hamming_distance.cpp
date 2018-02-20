#include <bitset>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {

        bitset<31> b1(x);
        bitset<31> b2(y);

        return (b1 ^ b2).count();
    }
};