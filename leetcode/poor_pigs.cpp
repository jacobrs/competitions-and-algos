class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        double divisor = (double)minutesToTest / (double)minutesToDie;
        double res = buckets;
        int pigCounter = 0;
        while(buckets > 1){
            buckets /= divisor;
            pigCounter ++;
        }
        return pigCounter;
    }
};
