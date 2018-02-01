#include <string>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string result;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        while(i >= 0 && j >= 0){
            int res = (num1[i] - 48) + (num2[j] - 48);
            result.insert(0, handle_carry(carry, res));
            i--;
            j--;
        }
        while(i >= 0){
            int res = (num1[i] - 48);
            res += carry;
            result.insert(0, handle_carry(carry, res));
            i--;
        }
        while(j >= 0){
            int res = (num2[j] - 48);
            res += carry;
            result.insert(0, handle_carry(carry, res));
            j--;
        }
        if(carry > 0){
            result = "1" + result;
        }
        return result;
    }

    string handle_carry(int& carry, int res){
        res += carry;
        if(res >= 10){
            res = res - 10;
            carry = 1;
        }else{
            carry = 0;
        }
        return to_string(res);
    }
};