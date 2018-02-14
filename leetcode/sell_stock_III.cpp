#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        return _helper(prices);
    }

    int _helper(vector<int>& prices){
        int firstSell = 0;
        int secondSell = 0;
        int firstBuy = -10000000;
        int secondBuy = -100000000;

        for (auto p : prices) {
            _helperT1(p, firstBuy, firstSell);
            _helperT2(p, secondBuy, secondSell, firstSell);
        }

        return (secondSell > firstSell) ? secondSell : firstSell;
    }

    void _helperT1(int price, int& buy, int& sell){
        buy = (buy > (-price)) ? buy: price;
        sell = (sell > (buy + price)) ? sell : price - buy;
    }

    void _helperT2(int price, int& buy, int& sell, int& beat){
        int fullAmountToBeat = (beat - price);
        buy = (buy > fullAmountToBeat) ? buy : fullAmountToBeat;
        sell = (sell > buy + price) ? sell : buy + price;
    }
};
