#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        char last = ' ';
        int count = 0;
        string output;
        for(auto c : chars){
            if(c != last){
                if(last != ' ') {
                    if (count <= 1) {
                        output += last;
                    } else {
                        output += last + to_string(count);
                    }
                }
                last = c;
                count = 1;
            }else{
                count ++;
            }
        }

        if(count <= 1){
            output += last;
        }else{
            output += last + to_string(count);
        }

        for(int i = 0; i < output.length(); i++){
            chars[i] = output[i];
        }

        return output.length();
    }
};